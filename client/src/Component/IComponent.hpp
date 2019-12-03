/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_ICOMPONENT_HPP
#define RTYPE_ICOMPONENT_HPP

#include "Game/KeyBind.hpp"
#include "Network/Network.hpp"
#include <SFML/Graphics.hpp>

namespace Client {
    class IComponent {
    public:
        virtual ~IComponent() = default;
        virtual void place(const sf::Vector2f &position) = 0;
        virtual bool event(Client::Network &network, const Client::KeyBind &keyBind, const sf::Event &event, const sf::Clock &clock) = 0;
        virtual void render(sf::RenderWindow &window) = 0;
    };
}

#endif
