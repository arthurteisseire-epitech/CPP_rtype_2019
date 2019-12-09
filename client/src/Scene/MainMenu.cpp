/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** MainMenu.cpp
*/

#include <cmath>
#include "MainMenu.hpp"
#include "OptionsMenu.hpp"
#include "PlayMenu.hpp"

static const std::vector<sf::Vector2<float>> buttonPosList({
    {0.372f, 0.2f},
    {0.32f, 0.4f},
    {0.268f, 0.6f}
});

Client::MainMenu::MainMenu() : _sprites({
    new Client::Image(0, 1, {0.5f, 0.5f}, "MenuBgL.png"),
    new Client::Image(1, 0, {0.5f, 0.5f}, "MenuBgR.png")
}), _buttons({
    {new Client::Button(2, 2, buttonPosList[0], "ButtonPlay.png"), &Client::MainMenu::play},
    {new Client::Button(3, 2, buttonPosList[1], "ButtonOptions.png"), &Client::MainMenu::options},
    {new Client::Button(4, 2, buttonPosList[2], "ButtonQuit.png"), &Client::MainMenu::quit}
}), _clock(), _quitRefTime(-1)
{
}

Client::MainMenu::~MainMenu()
{
    for (auto &sprite : _sprites) {
        delete sprite;
    }
    for (auto &button : _buttons) {
        delete button.first;
    }
}

void Client::MainMenu::event(Client::IScene *&self, sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    if (_quitRefTime < 0.f) {
        for (auto &button : _buttons) {
            if (button.first->event(event, keyBind, network, window)) {
                (this->*button.second)(self);
            }
        }
    }
}

void Client::MainMenu::update(Client::IScene *&self, Client::Network &network, Client::Window &window)
{
    float quitTime = std::pow(_clock.getElapsedTime().asSeconds() - _quitRefTime, 3.f);
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

void Client::MainMenu::render(Client::Window &window)
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

void Client::MainMenu::play(Client::IScene *&self)
{
    Client::IScene *currentScene = self;
    self = new PlayMenu();
    delete currentScene;
}

void Client::MainMenu::options(Client::IScene *&self)
{
    Client::IScene *currentScene = self;
    self = new OptionsMenu();
    delete currentScene;
}

void Client::MainMenu::quit(Client::IScene *&self)
{
    _quitRefTime = _clock.getElapsedTime().asSeconds();
}