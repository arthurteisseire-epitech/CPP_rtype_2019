/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Loader.hpp
*/

#ifndef RTYPE_LOADER_HPP
#define RTYPE_LOADER_HPP

#include "IComponent.hpp"

namespace Client {
    class Loader : public IComponent {
    public:
        Loader(uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath);
        ~Loader() override = default;
        void move(const sf::Vector2<float> &position) override;
        void adjust(Client::Window &window) override;
        void place(Client::Window &window) override;
        bool event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window) override;
        void update(Client::Network &network, Client::Window &window) override;
        void render(Client::Window &window, uint8_t layer) override;
        std::string getIdentity() const override;
        uint32_t getId() const override;
    private:
        uint8_t _layer;
        sf::Vector2<float> _position;
        sf::Clock _clock;
        sf::Texture *_texture;
        sf::Sprite _sprite;
    };
}

#endif