/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** MainMenu.hpp
*/

#ifndef RTYPE_SHIP_HPP
#define RTYPE_SHIP_HPP

#include "IComponent.hpp"

namespace Client {
    class Ship : public IComponent {
    public:
        Ship(uint32_t id, uint8_t layer, const std::string &texturePath, bool controlled);
        ~Ship() override;
        void move(const sf::Vector2<float> &position) override;
        void adjust(Client::Window &window) override;
        void place(Client::Window &window) override;
        bool event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window) override;
        void update(Client::Network &network, Client::Window &window) override;
        void render(Client::Window &window, uint8_t layer) override;
        uint32_t getId() const;
        bool isControlled() const;
    private:
        uint32_t _id;
        uint8_t _layer;
        bool _controlled;
        sf::Vector2<float> _position;
        sf::Texture *_texture;
        sf::Sprite _sprite;
    };
}

#endif