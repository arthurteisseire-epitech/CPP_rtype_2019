/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Entity.hpp
*/

#ifndef RTYPE_ENTITY_HPP
#define RTYPE_ENTITY_HPP

#include "IComponent.hpp"

namespace Client {
    class Entity : public IComponent {
    public:
        Entity(uint32_t id, uint8_t layer, const std::string &identity, const sf::Vector2<float> &position, const std::string &texturePath, const sf::Vector2<uint32_t> &layout);
        ~Entity() override = default;
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
        uint32_t _id;
        uint8_t _layer;
        std::string _identity;
        sf::Vector2<float> _position;
        sf::Clock _clock;
        sf::Texture *_texture;
        sf::Sprite _sprite;
    };
}

#endif