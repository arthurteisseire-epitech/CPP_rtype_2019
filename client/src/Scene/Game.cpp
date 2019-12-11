/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Game.cpp
*/

#include "Component/Fading.hpp"
#include "Component/SideScroller.hpp"
#include "Game.hpp"

Client::Game::Game(Client::IScene *prev) :
    _prev(prev), _components({
        new Client::SideScroller(0, "Background.png", 0.1f),
        new Client::Fading(254, 0.5f, 0.5f, true)
    }), _players({nullptr, nullptr, nullptr, nullptr})
{
}

Client::Game::Game(std::array<Client::Ship *, 4> &players, Client::IScene *prev) :
    _prev(prev), _components({
        new Client::SideScroller(0, "Background.png", 0.1f),
        new Client::Fading(254, 0.5f, 0.5f, true)
    }), _players(players)
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
    for (uint8_t i = 0; _players[i]; i++) {
        _players[i]->event(event, keyBind, network, window);
    }
}

void Client::Game::update(Client::IScene *&self, Client::Network &network, Client::Window &window)
{
    if (!_players[0]) {
        Client::Packet packet(network.findReceived(PACKET_PLAYER_CONNECTED));
        _players[0] = new Client::Ship(packet.getId(), 128, "Ship.png", true);
    }
    for (auto &component : _components) {
        component->update(network, window);
    }
    for (uint8_t i = 0; _players[i]; i++) {
        _players[i]->update(network, window);
    }
}

void Client::Game::render(Client::Window &window)
{
    for (uint8_t layer = 0; layer < 255; layer++) {
        for (auto &component : _components) {
            component->render(window, layer);
        }
        for (uint8_t i = 0; _players[i]; i++) {
            _players[i]->render(window, layer);
        }
    }
}