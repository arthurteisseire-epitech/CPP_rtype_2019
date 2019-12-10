/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Game.cpp
*/

#include "Game.hpp"

Client::Game::Game(Client::IScene *prev)
{
}

Client::Game::~Game()
{
    delete _prev;
}

void Client::Game::event(Client::IScene *&self, sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
}

void Client::Game::update(Client::IScene *&self, Client::Network &network, Client::Window &window)
{
}

void Client::Game::render(Client::Window &window)
{
}