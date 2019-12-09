/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** PlayMenu.cpp
*/

#include "PlayMenu.hpp"

static const std::vector<sf::Vector2<float>> buttonPosList({});

Client::PlayMenu::PlayMenu() : _sprites(), _buttons(), _clock(), _quitRefTime(-1)
{
}

Client::PlayMenu::~PlayMenu()
{
}

void Client::PlayMenu::event(Client::IScene *&self, sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    if (_quitRefTime < 0.f) {
        for (auto &button : _buttons) {
            if (button.first->event(event, keyBind, network, window)) {
                (this->*button.second)(self);
            }
        }
    }
}

void Client::PlayMenu::update(Client::IScene *&self, Client::Network &network, Client::Window &window)
{
    float quitTime = _clock.getElapsedTime().asSeconds() - _quitRefTime;
    if (_quitRefTime >= 0.f) {
        _sprites[0]->move({0.5f - quitTime, 0.5f});
        uint8_t i = 0;
        for (auto &button : _buttons) {
            button.first->move({buttonPosList[i].x - quitTime, buttonPosList[i].y});
            i++;
        }
        if (quitTime > 0.5f) {
            window.close();
        }
    }
    for (auto &sprite : _sprites) {
        sprite->update(network, window);
    }
    for (auto &button : _buttons) {
        button.first->update(network, window);
    }
}

void Client::PlayMenu::render(Client::Window &window)
{
    for (uint8_t layer = 0; layer < 255; layer++) {
        for (auto &sprite : _sprites) {
            sprite->render(window, layer);
        }
        for (auto &button : _buttons) {
            button.first->render(window, layer);
        }
    }
}