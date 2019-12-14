/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Vleb
*/

#ifndef RTYPE_ISCENE_HPP
#define RTYPE_ISCENE_HPP

#include <SFML/Graphics.hpp>
#include "Game/KeyBind.hpp"
#include "Game/Window.hpp"
#include "Network/Network.hpp"

namespace Client {
    class IScene {
    public:
        virtual ~IScene() = default;
        virtual void event(Client::IScene *&self, sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window) = 0;
        virtual void update(Client::IScene *&self, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window) = 0;
        virtual void render(Client::Window &window) = 0;
    };
}

#endif
