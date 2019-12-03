/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Vleb
*/

#include "KeyBind.hpp"

Client::KeyBind::KeyBind() : _bind()
{
    _bind[sf::Keyboard::Key::Up] = sf::Keyboard::Key::Up;
    _bind[sf::Keyboard::Key::Down] = sf::Keyboard::Key::Down;
    _bind[sf::Keyboard::Key::Left] = sf::Keyboard::Key::Left;
    _bind[sf::Keyboard::Key::Right] = sf::Keyboard::Key::Right;
    _bind[sf::Keyboard::Key::Space] = sf::Keyboard::Key::Space;
    _bind[sf::Keyboard::Key::Enter] = sf::Keyboard::Key::Enter;
    _bind[sf::Keyboard::Key::Escape] = sf::Keyboard::Key::Escape;
}

void Client::KeyBind::rebind(const sf::Keyboard::Key bind, const sf::Keyboard::Key action)
{
    for (auto &pair : _bind) {
        if (pair.second == action) {
            _bind.erase(_bind.find(pair.first));
            break;
        }
    }
    _bind[bind] = action;
}

sf::Keyboard::Key Client::KeyBind::getAction(const sf::Keyboard::Key bind)
{
    return _bind[bind];
}

bool Client::KeyBind::isBound(const sf::Keyboard::Key bind)
{
    return _bind.find(bind) != _bind.end();
}