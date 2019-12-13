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
        Button(uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath);
        Button(uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath, const std::string &textureAltPath, bool invert = false);
        ~Button() override;
        void move(const sf::Vector2<float> &position) override;
        void adjust(Client::Window &window) override;
        void place(Client::Window &window) override;
        bool event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window) override;
        void update(Client::Network &network, Client::Window &window) override;
        void render(Client::Window &window, uint8_t layer) override;
        bool collide(Client::IComponent *component, Client::Window &window) override;
        std::string getIdentity() const override;
        uint32_t getId() const override;
        sf::Vector2<float> getPosition() const override;
        sf::Vector2<float> getSpriteSize() const override;
    private:
        void invert();
        uint8_t _layer;
        sf::Vector2<float> _position;
        sf::Texture *_texture;
        sf::Texture *_textureAlt;
        sf::Sprite _sprite;
    };
}

#endif