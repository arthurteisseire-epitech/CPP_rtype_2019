/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** OptionsMenu.cpp
*/

#include <cmath>
#include "CommonMenu.hpp"
#include "MainMenu.hpp"
#include "OptionsMenu.hpp"

static const std::vector<sf::Vector2<float>> buttonPosList({
    {0.372f, 0.2f},
    {0.32f, 0.4f},
    {0.268f, 0.6f}
});

Client::OptionsMenu::OptionsMenu(const Client::Window &window, Client::IScene *prev) :
    _prev(prev), _components({
        new Client::Image(1, {-0.5f, 0.5f}, "Menu/MenuBgL.png"),
        new Client::Image(0, {0.5f, 0.5f}, "Menu/MenuBgR.png")
    }), _buttons({
        {new Client::Button(2, buttonPosList[0], "Menu/ButtonSoundOff.png", "Menu/ButtonSoundOn.png", window.getSound()), &Client::OptionsMenu::sound},
        {new Client::Button(2, buttonPosList[1], "Menu/ButtonVsyncOff.png", "Menu/ButtonVsyncOn.png", window.getVsync()), &Client::OptionsMenu::vsync},
        {new Client::Button(2, buttonPosList[2], "Menu/ButtonBack.png"), &Client::OptionsMenu::back}
    }), _clock(), _quitRefTime(-1.f), _next(nullptr)
{
}

Client::OptionsMenu::~OptionsMenu()
{
    MENU_DTOR
}

void Client::OptionsMenu::event(Client::IScene *&self, sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    MENU_EVENT
}

void Client::OptionsMenu::update(Client::IScene *&self, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    MENU_UPDATE
}

void Client::OptionsMenu::render(Client::Window &window)
{
    MENU_RENDER
}

void Client::OptionsMenu::sound(Client::Window &window)
{
    window.switchSound();
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