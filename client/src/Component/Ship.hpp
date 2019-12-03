/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Menu.hpp
*/

#ifndef RTYPE_SHIP_HPP
#define RTYPE_SHIP_HPP

#include "IComponent.hpp"

namespace Client {
    class Ship : public IComponent {
    public:
        Ship(uint32_t id, const std::string &texturePath, bool controlled = true);
        ~Ship() override = default;
        void place(const sf::Vector2<float> &position) override;
        bool event(Client::Network &network, Client::KeyBind &keyBind, const sf::Event &event) override;
        void render(Client::Network &network, sf::RenderWindow &window) override;
    private:
        uint32_t _id;
        bool _controlled;
        sf::Sprite _sprite;
    };
}

#endif