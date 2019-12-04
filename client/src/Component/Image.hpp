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
    class Image : public IComponent {
    public:
        Image(uint32_t id, uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath);
        ~Image() override = default;
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
        sf::Vector2<float> _position;
        sf::Sprite _sprite;
    };
}

#endif