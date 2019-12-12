/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_ICOMPONENT_HPP
#define RTYPE_ICOMPONENT_HPP

#define ASSETS_DIR "../../client/assets/"

#include <cstdint>
#include <SFML/Graphics.hpp>
#include "Game/KeyBind.hpp"
#include "Game/Window.hpp"
#include "Network/Network.hpp"

namespace Client {
    class IComponent {
    public:
        virtual ~IComponent() = default;
        virtual void move(const sf::Vector2<float> &position) = 0;
        virtual void adjust(Client::Window &window) = 0;
        virtual void place(Client::Window &window) = 0;
        virtual bool event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window) = 0;
        virtual void update(Client::Network &network, Client::Window &window) = 0;
        virtual void render(Client::Window &window, uint8_t layer) = 0;
        virtual std::string getIdentity() const = 0;
        virtual uint32_t getId() const = 0;
    };
}

#endif
