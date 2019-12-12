/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SpriteSheet.hpp
*/

#ifndef RTYPE_SPRITESHEET_HPP
#define RTYPE_SPRITESHEET_HPP

#include "IComponent.hpp"

namespace Client {
    class SpriteSheet : public IComponent {
    public:
        SpriteSheet(uint32_t id, uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath, const sf::Vector2<uint32_t> &layout);
        ~SpriteSheet() override = default;
        void move(const sf::Vector2<float> &position) override;
        void adjust(Client::Window &window) override;
        void place(Client::Window &window) override;
        bool event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window) override;
        void update(Client::Network &network, Client::Window &window) override;
        void render(Client::Window &window, uint8_t layer) override;
        uint32_t getId() const override;
    private:
        uint32_t _id;
        uint8_t _layer;
        sf::Vector2<float> _position;
        sf::Clock _clock;
        sf::Texture *_texture;
        sf::Sprite _sprite;
    };
}

#endif