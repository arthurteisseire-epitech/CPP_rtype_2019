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
    }), _playerNb(1), _clock(), _quitRefTime(-1.f), _next(nullptr)
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

void Client::OnlineMenu::update(Client::IScene *&self, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    static bool serverUp = false;
    if (!serverUp) {
        Client::Packet packet(network.findReceived(PACKET_PLAYER_CONNECTED));
        serverUp = true;
        network.send(Client::Packet(PACKET_GAME_REQUEST).getRaw());
    }
    try {
        Client::Packet packet(network.findReceived(PACKET_MATE_CONNECTED));
        _playerNb++;
    } catch (std::runtime_error &packetNotFound) {}
    try {
        Client::Packet packet(network.findReceived(PACKET_MATE_LOST));
        _playerNb--;
    } catch (std::runtime_error &packetNotFound) {}
    float clockTime(_clock.getElapsedTime().asSeconds());
    if (_quitRefTime < 0.f) {
        if (_playerNb == 4 || clockTime > 60.f) {
            _components.push_back(new Client::Fading(1, 0.5f));
            _quitRefTime = clockTime;
            _next = new Client::Game(true, this);
        }
    } else if (clockTime - _quitRefTime > 0.5f) {
        self = _next;
        self->update(self, keyBind, network, window);
    }
    for (auto &component : _components) {
        component->update(keyBind, network, window);
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