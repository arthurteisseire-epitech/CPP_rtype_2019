/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Game.cpp
*/

#include <map>
#include <sstream>
#include "Component/Fading.hpp"
#include "Component/SideScroller.hpp"
#include "Component/Entity.hpp"
#include "Game.hpp"

static const std::map<std::string, std::pair<std::string, sf::Vector2<uint32_t>>> entityData({
    {"alien", {"Alien.png", {1, 1}}},
    {"missile_fire1", {"MissileFire1.png", {1, 1}}},
    {"missile_fire2", {"MissileFire2.png", {1, 1}}},
    {"missile_standard", {"MissileStandard.png", {1, 1}}},
    {"missile_inverted", {"MissileInverted.png", {1, 1}}}
});

Client::Game::Game(Client::IScene *prev) :
    _prev(prev), _components({
        new Client::SideScroller(0, "Background.png", 0.1f),
        new Client::Fading(3, 0.5f, 0.5f, true)
    }), _start(true)
{
}

Client::Game::Game(std::array<Client::Ship *, 4> &players, Client::IScene *prev) :
    _prev(prev), _components({
        new Client::SideScroller(0, "Background.png", 0.1f),
        new Client::Fading(3, 0.5f, 0.5f, true)
    }), _start(true)
{
    for (uint8_t i = 0; players[i]; i++) {
        _components.push_back(players[i]);
    }
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
    for (auto &component : _components) {
        component->event(event, keyBind, network, window);
    }
}

void Client::Game::update(Client::IScene *&self, Client::Network &network, Client::Window &window)
{
    if (_start) {
        if (_components.size() == 2) {
            Client::Packet packet(network.findReceived(PACKET_PLAYER_CONNECTED));
            uint32_t packetId(packet.getId());
            _components.push_back(new Client::Ship(packetId, 1, "Ship.png", true));
            network.send(Client::Packet(PACKET_START_GAME, packetId).getRaw());
        }
        network.emptyBuffer();
        _start = false;
    }
    for (uint64_t i = 0; true; i++) {
        try {
            Client::Packet packet(network.findReceived(i));
            std::vector<std::string> payload(packet.getParsedPayload());
            uint32_t packetId(packet.getId());
            if (payload[0] == PACKET_ENTITY_SET) {
                network.removeFromBuffer(i);
                std::istringstream coordStream(payload[2]);
                std::string coordStr;
                std::vector<float> coordList;
                while (std::getline(coordStream, coordStr, ',')) {
                    coordList.push_back(std::stof(coordStr));
                }
                sf::Vector2<float> coord(coordList[0], coordList[1]);
                if (coord.x < -0.5f || coord.x > 1.5f || coord.y < -0.5f || coord.y > 1.5f) {
                    continue;
                }
                bool componentExists(false);
                for (auto &component : _components) {
                    if (packetId == component->getId()) {
                        if (payload[1] == component->getIdentity()) {
                            component->move(coord);
                        } else {
                            delete component;
                            std::pair<std::string, sf::Vector2<uint32_t>> data = entityData.find(payload[1])->second;
                            component = new Client::Entity(packetId, 2, payload[1], coord, data.first, data.second);
                        }
                        componentExists = true;
                        break;
                    }
                }
                if (!componentExists) {
                    if (payload[1] == "ship") {
                        _components.push_back(new Client::Ship(packetId, 1, "Ship.png", false));
                    } else {
                        std::pair<std::string, sf::Vector2<uint32_t>> data = entityData.find(payload[1])->second;
                        _components.push_back(new Client::Entity(packetId, 2, payload[1], coord, data.first, data.second));
                    }
                }
            }
        } catch (std::logic_error &parsingError) {
            continue;
        } catch (std::runtime_error &noMorePacket) {
            break;
        }
    }
    for (auto &component : _components) {
        component->update(network, window);
    }
}

void Client::Game::render(Client::Window &window)
{
    for (uint8_t layer = 0; layer < 255; layer++) {
        for (auto &component : _components) {
            component->render(window, layer);
        }
    }
}