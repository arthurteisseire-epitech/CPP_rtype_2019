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
        Ship(uint32_t id, uint8_t layer, const std::string &texturePath, bool controlled = true);
        ~Ship() override = default;
        void adjust(Client::Window &window) override;
        void place(const sf::Vector2<float> &ratio, Client::Window &window) override;
        bool event(Client::Network &network, Client::KeyBind &keyBind, const sf::Event &event) override;
        void update(Client::Network &network, Client::Window &window) override;
        void render(Client::Window &window, uint8_t layer) override;
    private:
        void adjust(const sf::Vector2<float> &scale) override;
        void place(const sf::Vector2<float> &position) override;
        uint32_t _id;
        uint8_t _layer;
        bool _controlled;
        sf::Sprite _sprite;
    };
}

#endif