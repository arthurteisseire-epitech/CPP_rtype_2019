/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** PlayMenu.cpp
*/

#include "MainMenu.hpp"
#include "PlayMenu.hpp"

static const std::vector<sf::Vector2<float>> buttonPosList({
    {0.268f, 0.6f}
});

Client::PlayMenu::PlayMenu(Client::IScene *prev) : _prev(prev), _images({
    new Client::Image(0, 1, {0.5f, 0.5f}, "MenuBgL.png"),
    new Client::Image(1, 0, {0.5f, 0.5f}, "MenuBgR.png")
}), _buttons({
    {new Client::Button(2, 2, buttonPosList[0], "ButtonBack.png"), &Client::PlayMenu::back}
}), _clock(), _quitRefTime(-1)
{
}

Client::PlayMenu::~PlayMenu()
{
    delete _prev;
    for (auto &image : _images) {
        delete image;
    }
    for (auto &button : _buttons) {
        delete button.first;
    }
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
        _images[0]->move({0.5f - quitTime, 0.5f});
        uint8_t i = 0;
        for (auto &button : _buttons) {
            button.first->move({buttonPosList[i].x - quitTime, buttonPosList[i].y});
            i++;
        }
        if (quitTime > 0.5f) {
            window.close();
        }
    }
    for (auto &image : _images) {
        image->update(network, window);
    }
    for (auto &button : _buttons) {
        button.first->update(network, window);
    }
}

void Client::PlayMenu::render(Client::Window &window)
{
    for (uint8_t layer = 0; layer < 255; layer++) {
        for (auto &image : _images) {
            image->render(window, layer);
        }
        for (auto &button : _buttons) {
            button.first->render(window, layer);
        }
    }
}

void Client::PlayMenu::back(Client::IScene *&self)
{
    self = new Client::MainMenu(this);
}