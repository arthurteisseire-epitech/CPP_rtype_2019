/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** OptionsMenu.cpp
*/

#include <cmath>
#include "MainMenu.hpp"
#include "OptionsMenu.hpp"

static const std::vector<sf::Vector2<float>> buttonPosList({
    {0.372f, 0.2f},
    {0.32f, 0.4f},
    {0.268f, 0.6f}
});

Client::OptionsMenu::OptionsMenu(const Client::Window &window, Client::IScene *prev) : _prev(prev), _images({
    new Client::Image(0, 1, {-0.5f, 0.5f}, "MenuBgL.png"),
    new Client::Image(1, 0, {0.5f, 0.5f}, "MenuBgR.png")
}), _buttons({
    {new Client::Button(2, 2, buttonPosList[0], "ButtonWinOn.png", "ButtonWinOff.png", window.getFullscreen()), &Client::OptionsMenu::window},
    {new Client::Button(3, 2, buttonPosList[1], "ButtonVsyncOff.png", "ButtonVsyncOn.png", window.getVsync()), &Client::OptionsMenu::vsync},
    {new Client::Button(4, 2, buttonPosList[2], "ButtonBack.png"), &Client::OptionsMenu::back}
}), _clock(), _quitRefTime(-1), _next(nullptr)
{
}

Client::OptionsMenu::~OptionsMenu()
{
    delete _prev;
    for (auto &image : _images) {
        delete image;
    }
    for (auto &button : _buttons) {
        delete button.first;
    }
}

void Client::OptionsMenu::event(Client::IScene *&self, sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    if (_quitRefTime < 0.f) {
        for (auto &button : _buttons) {
            if (button.first->event(event, keyBind, network, window)) {
                (this->*button.second)(window);
            }
        }
    }
}

void Client::OptionsMenu::update(Client::IScene *&self, Client::Network &network, Client::Window &window)
{
    float clockTime(_clock.getElapsedTime().asSeconds());
    float spawnTime((clockTime - 0.5f) * 2.f);
    if (spawnTime < 1.f) {
        _images[0]->move({-0.5f + spawnTime, 0.5f});
        uint8_t i = 0;
        for (auto &button : _buttons) {
            button.first->move({buttonPosList[i].x - 1.f + spawnTime, buttonPosList[i].y});
            i++;
        }
    } else if (_quitRefTime > 0.f) {
        float quitTime(std::pow((clockTime - _quitRefTime) * 2.f, 4.f));
        _images[0]->move({0.5f - quitTime, 0.5f});
        uint8_t i = 0;
        for (auto &button : _buttons) {
            button.first->move({buttonPosList[i].x - quitTime, buttonPosList[i].y});
            i++;
        }
        if (quitTime > 0.5f) {
            self = _next;
            self->update(self, network, window);
        }
    } else {
        _images[0]->move({0.5f, 0.5f});
        uint8_t i = 0;
        for (auto &button : _buttons) {
            button.first->move({buttonPosList[i].x, buttonPosList[i].y});
            i++;
        }
    }
    for (auto &image : _images) {
        image->update(network, window);
    }
    for (auto &button : _buttons) {
        button.first->update(network, window);
    }
}

void Client::OptionsMenu::render(Client::Window &window)
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

void Client::OptionsMenu::window(Client::Window &window)
{
    window.switchFullscreen();
}

void Client::OptionsMenu::vsync(Client::Window &window)
{
    window.switchVsync();
}

void Client::OptionsMenu::back(Client::Window &window)
{
    _next = new Client::MainMenu(this);
    _quitRefTime = _clock.getElapsedTime().asSeconds();
}