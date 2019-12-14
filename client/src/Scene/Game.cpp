/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Game.cpp
*/

#include <cmath>
#include <map>
#include <sstream>
#include "Component/Button.hpp"
#include "Component/Entity.hpp"
#include "Component/Fading.hpp"
#include "Component/Image.hpp"
#include "Component/SideScroller.hpp"
#include "Game.hpp"
#include "Menu/MainMenu.hpp"

static const std::map<std::string, std::pair<std::string, sf::Vector2<uint32_t>>> entityData({
    {"alien1", {"Game/Alien1.png", {8, 2}}},
    {"alien2", {"Game/Alien2.png", {8, 2}}},
    {"blast_stage1", {"Game/BlastStage1.png", {1, 1}}},
    {"blast_stage2", {"Game/BlastStage2.png", {1, 1}}},
    {"blast_stage3", {"Game/BlastStage3.png", {2, 1}}},
    {"enemy_blast_stage1", {"Game/EnemyBlastStage1.png", {1, 1}}},
    {"enemy_blast_stage2", {"Game/EnemyBlastStage2.png", {1, 1}}},
    {"enemy_blast_stage3", {"Game/EnemyBlastStage3.png", {2, 1}}},
    {"enemy_ship1", {"Game/EnemyShip1.png", {8, 1}}},
    {"enemy_ship2", {"Game/EnemyShip2.png", {8, 1}}},
    {"power_up", {"Game/PowerUp.png", {12, 1}}},
    {"vortex", {"Game/Vortex.png", {3, 1}}}
});

static const std::map<std::string, void (Client::Game::*)(const std::vector<std::string> &, const uint32_t &)> entityAction({
    {PACKET_ENTITY_DELETE, &Client::Game::deleteEntity},
    {PACKET_ENTITY_SET, &Client::Game::setEntity}
});

static const std::vector<std::pair<std::string, std::string>> entityCollision({
    {"alien1", "blast_stage3"},
    {"alien1", "ship"},
    {"alien2", "blast_stage3"},
    {"alien2", "ship"},
    {"blast_stage3", "alien1"},
    {"blast_stage3", "alien2"},
    {"blast_stage3", "enemy_blast_stage3"},
    {"blast_stage3", "enemy_ship1"},
    {"blast_stage3", "enemy_ship2"},
    {"enemy_blast_stage3", "blast_stage3"},
    {"enemy_blast_stage3", "ship"},
    {"enemy_ship1", "blast_stage3"},
    {"enemy_ship1", "ship"},
    {"enemy_ship2", "blast_stage3"},
    {"enemy_ship2", "ship"},
    {"ship", "alien1"},
    {"ship", "alien2"},
    {"ship", "enemy_blast_stage3"},
    {"ship", "enemy_ship1"},
    {"ship", "enemy_ship2"}
});

static const std::vector<sf::Vector2<float>> buttonPosList({
    {0.372f, 0.2f},
    {0.32f, 0.4f},
    {0.268f, 0.6f}
});

Client::Game::Game(bool multi, Client::IScene *prev) :
    _prev(prev), _components({
        new Client::SideScroller(0, "Game/Background.png", 0.1f),
        new Client::Fading(3, 0.5f, 0.5f, true)
    }), _pauseComponents({
        {new Client::Image(4, {-0.5f, 0.5f}, "Menu/MenuBgL.png"), nullptr},
        {new Client::Button(5, buttonPosList[0], "Menu/ButtonPlay.png"), &Client::Game::play},
        {new Client::Button(5, buttonPosList[1], "Menu/ButtonMenu.png"), &Client::Game::menu},
        {new Client::Button(5, buttonPosList[2], "Menu/ButtonQuit.png"), &Client::Game::quit},
    }), _multi(multi), _status(init), _clock(), _quitRefTime(-1.f), _next(nullptr)
{
}

Client::Game::~Game()
{
    delete _prev;
    for (auto &component : _components) {
        delete component;
    }
}

void Client::Game::event(Client::IScene *&self, sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    if (event.type == sf::Event::KeyPressed && keyBind.isBound(event.key.code)) {
        switch (keyBind.getAction(event.key.code)) {
        case sf::Keyboard::Key::Escape:
            if (_status == run) {
                _status = pause;
                _clock.restart();
            } else if (_status == pause) {
                this->play(network, window);
            }
            break;
        default:
            break;
        }
    }
    if (_status == run) {
        for (auto &component : _components) {
            component->event(event, keyBind, network, window);
        }
    } else if (_status == pause) {
        for (auto &component : _pauseComponents) {
            if (component.first->event(event, keyBind, network, window)) {
                (this->*component.second)(network, window);
            }
        }
    }
}

void Client::Game::update(Client::IScene *&self, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    if (_status == init) {
        if (!_multi) {
            Client::Packet packet(network.findReceived(PACKET_PLAYER_CONNECTED));
            network.send(Client::Packet(PACKET_GAME_REQUEST).getRaw());
        }
        network.emptyBuffer();
        network.send(Client::Packet(PACKET_GAME_START).getRaw());
        _status = run;
    }
    for (uint64_t i = 0; true; i++) {
        try {
            Client::Packet packet(network.findReceived(i));
            std::vector<std::string> payload(packet.getParsedPayload());
            bool knownPacket(false);
            for (auto &action : entityAction) {
                if (action.first == payload[0]) {
                    knownPacket = true;
                    (this->*action.second)(payload, packet.getId());
                    break;
                }
            }
            if (knownPacket) {
                network.removeFromBuffer(i);
                i--;
            } else {
                packet.disableDestruction();
            }
        } catch (std::logic_error &parsingError) {
            continue;
        } catch (std::runtime_error &noMorePacket) {
            break;
        }
    }
    for (auto &component1 : _components) {
        for (auto &component2 : _components) {
            std::pair<uint32_t, uint32_t> collisionId(component1->getId(), component2->getId());
            if (!collisionId.first) {
                break;
            } else if (!collisionId.second || collisionId.first == collisionId.second) {
                continue;
            }
            std::pair<std::string, std::string> collisionIdentity(component1->getIdentity(), component2->getIdentity());
            bool isCollisionValid(false);
            for (auto &validCollision : entityCollision) {
                if (validCollision == collisionIdentity) {
                    isCollisionValid = true;
                }
            }
            if (isCollisionValid && component1->collide(component2, window)) {
                std::ostringstream payload;
                payload << PACKET_ENTITY_COLLISION << ':' << collisionId.first << ',' << collisionId.second;
                network.send(Client::Packet(payload.str(), collisionId.first).getRaw());
            }
        }
        component1->update(keyBind, network, window);
    }
    if (_status == pause) {
        this->pauseMenu(self, keyBind, network, window);
    }
}

void Client::Game::render(Client::Window &window)
{
    for (uint8_t layer = 0; layer < 255; layer++) {
        for (auto &component : _components) {
            component->render(window, layer);
        }
        if (_status == pause) {
            for (auto &component : _pauseComponents) {
                component.first->render(window, layer);
            }
        }
    }
}

void Client::Game::deleteEntity(const std::vector<std::string> &payload, const uint32_t &id)
{
    for (uint64_t i = 0; i < _components.size(); i++) {
        if (_components[i]->getId() == id) {
            delete _components[i];
            _components.erase(_components.begin() + i);
            break;
        }
    }
}

void Client::Game::setEntity(const std::vector<std::string> &payload, const uint32_t &id)
{
    std::istringstream coordStream(payload[2]);
    std::string coordStr;
    std::vector<float> coordList;
    while (std::getline(coordStream, coordStr, ',')) {
        coordList.push_back(std::stof(coordStr));
    }
    sf::Vector2<float> coord(coordList[0], coordList[1]);
    if (coord.x < -0.5f || coord.x > 1.5f || coord.y < -0.5f || coord.y > 1.5f) {
        return;
    }
    for (uint64_t i = 2; i < _components.size(); i++) {
        if (id == _components[i]->getId()) {
            if (payload[1] == _components[i]->getIdentity()) {
                _components[i]->move(coord);
                return;
            } else {
                delete _components[i];
                _components.erase(_components.begin() + i);
                break;
            }
        }
    }
    if (payload[1] == "ship") {
        _components.push_back(new Client::Ship(id, 1, "Game/Ship.png", payload.size() == 4 && payload[3] == "player"));
    } else {
        std::pair<std::string, sf::Vector2<uint32_t>> data = entityData.find(payload[1])->second;
        _components.push_back(new Client::Entity(id, 2, payload[1], coord, data.first, data.second));
    }
}

void Client::Game::pauseMenu(Client::IScene *&self, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    float clockTime(_clock.getElapsedTime().asSeconds());
    float spawnTime((clockTime - 0.5f) * 2.f);
    if (spawnTime < 1.f) {
        uint8_t i = 0;
        for (auto &component : _pauseComponents) {
            if (i == 0) {
                _pauseComponents[i].first->move({-0.5f + spawnTime, 0.5f});
            } else {
                _pauseComponents[i].first->move({buttonPosList[i - 1].x - 1.f + spawnTime, buttonPosList[i - 1].y});
            }
            i++;
        }
    } else if (_quitRefTime > 0.f) {
        float quitTime(std::pow((clockTime - _quitRefTime) * 2.f, 4.f));
        uint8_t i = 0;
        for (auto &component : _pauseComponents) {
            if (i == 0) {
                _pauseComponents[i].first->move({0.5f - quitTime, 0.5f});
            } else {
                _pauseComponents[i].first->move({buttonPosList[i - 1].x - quitTime, buttonPosList[i - 1].y});
            }
            i++;
        }
        if (quitTime > 0.5f) {
            if (_next) {
                self = _next;
                self->update(self, keyBind, network, window);
                network.send(Client::Packet(PACKET_CONNECT).getRaw());
            } else {
                _status = run;
                _quitRefTime = -1.f;
            }
        }
    } else {
        uint8_t i = 0;
        for (auto &component : _pauseComponents) {
            if (i == 0) {
                _pauseComponents[i].first->move({0.5f, 0.5f});
            } else {
                _pauseComponents[i].first->move({buttonPosList[i - 1].x, buttonPosList[i - 1].y});
            }
            i++;
        }
    }
    for (auto &component : _pauseComponents) {
        component.first->update(keyBind, network, window);
    }
}

void Client::Game::play(Client::Network &network, Client::Window &window)
{
    _quitRefTime = _clock.getElapsedTime().asSeconds();
}

void Client::Game::menu(Client::Network &network, Client::Window &window)
{
    network.send(Client::Packet(PACKET_DISCONNECT).getRaw());
    _next = new Client::MainMenu(this);
    _quitRefTime = _clock.getElapsedTime().asSeconds();
}

void Client::Game::quit(Client::Network &network, Client::Window &window)
{
    window.close();
}