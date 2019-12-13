/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** MainMenu.hpp
*/

#ifndef RTYPE_IMAGE_HPP
#define RTYPE_IMAGE_HPP

#include "IComponent.hpp"

namespace Client {
    class Image : public IComponent {
    public:
        Image(uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath);
        Image(uint32_t id, uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath);
        ~Image() override;
        void move(const sf::Vector2<float> &position) override;
        void adjust(Client::Window &window) override;
        void place(Client::Window &window) override;
        bool event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window) override;
        void update(Client::KeyBind &keyBind, Client::Network &network, Client::Window &window) override;
        void render(Client::Window &window, uint8_t layer) override;
        bool collide(Client::IComponent *component, Client::Window &window) override;
        std::string getIdentity() const override;
        uint32_t getId() const override;
        sf::Vector2<float> getPosition() const override;
        sf::Vector2<float> getSpriteSize() const override;
    private:
        uint8_t _layer;
        sf::Vector2<float> _position;
        sf::Texture *_texture;
        sf::Sprite _sprite;
    };
}

#endif