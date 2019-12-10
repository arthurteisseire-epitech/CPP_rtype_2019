/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** PlayMenu.cpp
*/

#include <cmath>
#include "CommonMenu.hpp"
#include "MainMenu.hpp"
#include "OnlineMenu.hpp"
#include "PlayMenu.hpp"
#include "Scene/Game.hpp"

static const std::vector<sf::Vector2<float>> buttonPosList({
    {0.372f, 0.2f},
    {0.32f, 0.4f},
    {0.268f, 0.6f}
});

Client::PlayMenu::PlayMenu(Client::IScene *prev) : _prev(prev), _components({
    new Client::Image(1, 1, {-0.5f, 0.5f}, "Menu/MenuBgL.png"),
    new Client::Image(2, 0, {0.5f, 0.5f}, "Menu/MenuBgR.png")
}), _buttons({
    {new Client::Button(3, 2, buttonPosList[0], "Menu/ButtonSolo.png"), &Client::PlayMenu::solo},
    {new Client::Button(4, 2, buttonPosList[1], "Menu/ButtonOnline.png"), &Client::PlayMenu::online},
    {new Client::Button(5, 2, buttonPosList[2], "Menu/ButtonBack.png"), &Client::PlayMenu::back}
}), _clock(), _quitRefTime(-1.f), _next(nullptr)
{
}

Client::PlayMenu::~PlayMenu()
{
    MENU_DTOR
}

void Client::PlayMenu::event(Client::IScene *&self, sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    MENU_EVENT
}

void Client::PlayMenu::update(Client::IScene *&self, Client::Network &network, Client::Window &window)
{
    MENU_UPDATE
}

void Client::PlayMenu::render(Client::Window &window)
{
    MENU_RENDER
}

void Client::PlayMenu::solo(Client::Window &window)
{
    _next = new Client::OnlineMenu(this);
    _components.push_back(new Client::Fading(5, 3, 0.5f));
    _quitRefTime = _clock.getElapsedTime().asSeconds();
}

void Client::PlayMenu::online(Client::Window &window)
{
    _next = new Client::OnlineMenu(this);
    _components.push_back(new Client::Fading(5, 3, 0.5f));
    _quitRefTime = _clock.getElapsedTime().asSeconds();
}

void Client::PlayMenu::back(Client::Window &window)
{
    _next = new Client::MainMenu(this);
    _quitRefTime = _clock.getElapsedTime().asSeconds();
}