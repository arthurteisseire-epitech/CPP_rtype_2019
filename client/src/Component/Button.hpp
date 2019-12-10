/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** MainMenu.hpp
*/

#ifndef RTYPE_BUTTON_HPP
#define RTYPE_BUTTON_HPP

#include "IComponent.hpp"

namespace Client {
    class Button : public IComponent {
    public:
        Button(uint32_t id, uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath);
        Button(uint32_t id, uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath, const std::string &textureAltPath, bool invert = false);
        ~Button() override;
        void move(const sf::Vector2<float> &position) override;
        void adjust(Client::Window &window) override;
        void place(Client::Window &window) override;
        bool event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window) override;
        void update(Client::Network &network, Client::Window &window) override;
        void render(Client::Window &window, uint8_t layer) override;
    private:
        void adjust(const sf::Vector2<float> &scale) override;
        void place(const sf::Vector2<float> &position) override;
        void invert();
        uint32_t _id;
        uint8_t _layer;
        sf::Vector2<float> _position;
        sf::Texture *_texture;
        sf::Texture *_textureAlt;
        sf::Sprite _sprite;
    };
}

#endif