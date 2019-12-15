/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Loader.cpp
*/

#include "CommonComponent.hpp"
#include "Loader.hpp"

Client::Loader::Loader(uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath) :
    _layer(layer), _position(position), _clock(), _texture(new sf::Texture())
{
    if (!_texture->loadFromFile(ASSETS_DIR + texturePath)) {
        throw std::runtime_error("\'Client::Loader::Loader\': Cannot load texture: " + texturePath);
    }
    _sprite = sf::Sprite(*_texture);
    _sprite.setOrigin(sf::Vector2<float>(_texture->getSize()) / 2.f);
}

void Client::Loader::move(const sf::Vector2<float> &position)
{
    _position = position;
}

void Client::Loader::adjust(Client::Window &window)
{
    COMPONENT_ADJUST
}

void Client::Loader::place(Client::Window &window)
{
    COMPONENT_PLACE
}

bool Client::Loader::event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    return false;
}

void Client::Loader::update(Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    _sprite.setRotation(_clock.getElapsedTime().asSeconds() * 360.f);
    this->adjust(window);
    this->place(window);
}

void Client::Loader::render(Client::Window &window, uint8_t layer)
{
    if (layer == _layer) {
        window.draw(_sprite);
    }
}

bool Client::Loader::collide(Client::IComponent *component, Client::Window &window)
{
    COMPONENT_COLLIDE
}

std::string Client::Loader::getIdentity() const
{
    return "identity";
}

uint32_t Client::Loader::getId() const
{
    return 0;
}

sf::Vector2<float> Client::Loader::getPosition() const
{
    return _position;
}

sf::Vector2<float> Client::Loader::getSpriteSize() const
{
    COMPONENT_SPRITE_SIZE
}

void Client::Loader::setLife(float life)
{
}