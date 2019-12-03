/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Vleb
*/

#ifndef RTYPE_ISCENE_HPP
#define RTYPE_ISCENE_HPP

#include "Network/INetwork.hpp"
#include "SFML/Graphics.hpp"

namespace Client {
    class IScene {
    public:
        virtual ~IScene() = default;
        virtual void getEvent(IScene *&self, INetwork &network, sf::RenderWindow &window) = 0;
        virtual void update(IScene *&self, INetwork &network, sf::RenderWindow &window) = 0;
    };
}

#endif
