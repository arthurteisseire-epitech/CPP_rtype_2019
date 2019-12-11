/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** OnlineMenu.cpp
*/

#include <string>
#include "OnlineMenu.hpp"
#include "Scene/Game.hpp"

Client::OnlineMenu::OnlineMenu(Client::IScene *prev) :
    _prev(prev), _components({
        new Client::Loader(0, {0.5f, 0.5f}, "Menu/Loader.png"),
        new Client::Image(0, {0.5f, 0.75f}, "Menu/WaitingMsg.png"),
        new Client::Image(0, {0.5f, 0.8f}, "Menu/WaitingTip.png"),
        new Client::Fading(1, 4.0f, 0.5f, true)
    }), _players({nullptr, nullptr, nullptr, nullptr}), _playerId(0), _clock(), _quitRefTime(-1.f), _next(nullptr)
{
}

Client::OnlineMenu::~OnlineMenu()
{
    delete _prev;
    for (auto &component : _components) {
        delete component;
    }
}

void Client::OnlineMenu::event(Client::IScene *&self, sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
}

void Client::OnlineMenu::update(Client::IScene *&self, Client::Network &network, Client::Window &window)
{
    try {
        Client::Packet packet(network.findReceived(PACKET_PLAYER_CONNECTED));
        _playerId = packet.getId();
        uint8_t i(0);
        for (i = 0; _players[i]; i++);
        if (i < _players.size()) {
            _players[i] = new Client::Ship(_playerId, 128, "Ship.png", true);
        }
    } catch (std::runtime_error &packetNotFound) {}
    try {
        Client::Packet packet(network.findReceived(PACKET_MATE_CONNECTED));
        uint8_t i(0);
        for (i = 0; _players[i]; i++);
        if (i < _players.size()) {
            _players[i] = new Client::Ship(packet.getId(), 128, "Ship.png", false);
        }
    } catch (std::runtime_error &packetNotFound) {}
    try {
        Client::Packet packet(network.findReceived(PACKET_MATE_LOST));
        for (uint8_t i = 0; _players[i]; i++) {
            if (_players[i]->getId() == packet.getId()) {
                delete _players[i];
                for (uint8_t j = i; _players[j]; j++) {
                    try {
                        _players[j] = _players[j + 1];
                    } catch (std::out_of_range &outOfRange) {
                        _players[j] = nullptr;
                    }
                }
                break;
            }
        }
    } catch (std::runtime_error &packetNotFound) {}
    float clockTime(_clock.getElapsedTime().asSeconds());
    if (_quitRefTime < 0.f) {
        if (_players.back() || clockTime > 60.f) {
            _components.push_back(new Client::Fading(1, 0.5f));
            _quitRefTime = clockTime;
            _next = new Client::Game(_players, this);
        }
    } else if (clockTime - _quitRefTime > 0.5f) {
        self = _next;
        self->update(self, network, window);
        network.send(Client::Packet(PACKET_START_GAME, _playerId).getRaw());
    }
    for (auto &component : _components) {
        component->update(network, window);
    }
}

void Client::OnlineMenu::render(Client::Window &window)
{
    for (uint8_t layer = 0; layer < 255; layer++) {
        for (auto &component : _components) {
            component->render(window, layer);
        }
    }
}