/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Fading.hpp
*/

#ifndef RTYPE_FADING_HPP
#define RTYPE_FADING_HPP

#include "IComponent.hpp"

namespace Client {
    class Fading : public IComponent {
    public:
        Fading(uint8_t layer, float duration, float delay = 0.f, bool invert = false);
        ~Fading() override = default;
        void move(const sf::Vector2<float> &position) override;
        void adjust(Client::Window &window) override;
        void place(Client::Window &window) override;
        bool event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window) override;
        void update(Client::Network &network, Client::Window &window) override;
        void render(Client::Window &window, uint8_t layer) override;
    private:
        void adjust(const sf::Vector2<float> &size) override;
        void place(const sf::Vector2<float> &position) override;
        uint8_t _layer;
        float _duration;
        float _delay;
        bool _invert;
        sf::Clock _clock;
        sf::RectangleShape _sprite;
    };
}

#endif