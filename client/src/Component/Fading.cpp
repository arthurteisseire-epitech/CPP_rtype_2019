/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Fading.cpp
*/

#include "CommonComponent.hpp"
#include "Fading.hpp"

Client::Fading::Fading(uint8_t layer, float duration, float delay, bool invert) :
    _layer(layer), _duration(duration), _delay(delay), _invert(invert), _clock(), _sprite()
{
    _sprite.setPosition(0.f, 0.f);
}

void Client::Fading::move(const sf::Vector2<float> &position)
{
}

void Client::Fading::adjust(Client::Window &window)
{
    _sprite.setSize(sf::Vector2<float>(window.getSize()));
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
    float clockTime(std::max(_clock.getElapsedTime().asSeconds() - _delay, 0.f));
    float progress(std::min(_invert ? std::max(_duration - clockTime, 0.f) : clockTime, _duration));
    _sprite.setFillColor({0, 0, 0, uint8_t(progress / _duration * 255)});
    this->adjust(window);
}

void Client::Fading::render(Client::Window &window, uint8_t layer)
{
    if (layer == _layer) {
        window.draw(_sprite);
    }
}

bool Client::Fading::collide(Client::IComponent *component, Client::Window &window)
{
    COMPONENT_COLLIDE
}

std::string Client::Fading::getIdentity() const
{
    return "fading";
}

uint32_t Client::Fading::getId() const
{
    return 0;
}

sf::Vector2<float> Client::Fading::getPosition() const
{
    return {0.5f, 0.5f};
}

sf::Vector2<float> Client::Fading::getSpriteSize() const
{
    return _sprite.getSize();
}