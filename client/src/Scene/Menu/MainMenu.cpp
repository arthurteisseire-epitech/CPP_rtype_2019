/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** MainMenu.cpp
*/

#include <cmath>
#include "CommonMenu.hpp"
#include "MainMenu.hpp"
#include "OptionsMenu.hpp"
#include "PlayMenu.hpp"

static const std::vector<sf::Vector2<float>> buttonPosList({
    {0.372f, 0.2f},
    {0.32f, 0.4f},
    {0.268f, 0.6f}
});

Client::MainMenu::MainMenu(Client::IScene *prev) :
    _prev(prev), _components({
        new Client::Image(1, {-0.5f, 0.5f}, "Menu/MenuBgL.png"),
        new Client::Image(0, {0.5f, 0.5f}, "Menu/MenuBgR.png")
    }), _buttons({
        {new Client::Button(2, buttonPosList[0], "Menu/ButtonPlay.png"), &Client::MainMenu::play},
        {new Client::Button(2, buttonPosList[1], "Menu/ButtonOptions.png"), &Client::MainMenu::options},
        {new Client::Button(2, buttonPosList[2], "Menu/ButtonQuit.png"), &Client::MainMenu::quit}
    }), _clock(), _quitRefTime(-1.f), _next(nullptr)
{
}

Client::MainMenu::~MainMenu()
{
    MENU_DTOR
}

void Client::MainMenu::event(Client::IScene *&self, sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    MENU_EVENT
}

void Client::MainMenu::update(Client::IScene *&self, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    MENU_UPDATE
}

void Client::MainMenu::render(Client::Window &window)
{
    MENU_RENDER
}

void Client::MainMenu::play(Client::Window &window)
{
    _next = new Client::PlayMenu(this);
    this->quit(window);
}

void Client::MainMenu::options(Client::Window &window)
{
    _next = new Client::OptionsMenu(window, this);
    this->quit(window);
}

void Client::MainMenu::quit(Client::Window &window)
{
    _quitRefTime = _clock.getElapsedTime().asSeconds();
}