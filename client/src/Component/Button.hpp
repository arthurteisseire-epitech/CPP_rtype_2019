/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Menu.hpp
*/

#ifndef RTYPE_BUTTON_HPP
#define RTYPE_BUTTON_HPP

#include "IComponent.hpp"

namespace Client {
    class Button : public IComponent {
    public:
        Button(uint32_t id, const std::string &texturePath);
        ~Button() override = default;
        void place(const sf::Vector2f &position) override;
        bool event(Client::Network &network, const Client::KeyBind &keyBind, const sf::Event &event, const sf::Clock &clock) override;
        void render(sf::RenderWindow &window) override;
    private:
        uint32_t _id;
        sf::Sprite _sprite;
    };
}

#endif