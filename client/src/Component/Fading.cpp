/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Fading.cpp
*/

#include "Fading.hpp"

Client::Fading::Fading(uint32_t id, uint8_t layer, float duration, bool invert) :
    _id(id), _layer(layer), _duration(duration), _invert(invert), _clock(), _sprite()
{
    _sprite.setPosition(0.f, 0.f);
}

void Client::Fading::move(const sf::Vector2<float> &position)
{
}

void Client::Fading::adjust(Client::Window &window)
{
    this->adjust(sf::Vector2<float>(window.getSize()));
}

void Client::Fading::place(Client::Window &window)
{
}

bool Client::Fading::event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    return false;
}

void Client::Fading::update(Client::Network &network, Client::Window &window)
{
    float clockTime(_clock.getElapsedTime().asSeconds());
    float progress(_invert ? std::max(_duration - clockTime, 0.f) : std::min(clockTime, _duration));
    _sprite.setFillColor({0, 0, 0, uint8_t(progress / _duration * 255)});
    this->adjust(window);
}

void Client::Fading::render(Client::Window &window, uint8_t layer)
{
    if (layer == _layer) {
        window.draw(_sprite);
    }
}

void Client::Fading::adjust(const sf::Vector2<float> &size)
{
    _sprite.setSize(size);
}

void Client::Fading::place(const sf::Vector2<float> &position)
{
}