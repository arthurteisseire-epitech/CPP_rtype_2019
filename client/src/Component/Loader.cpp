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
        throw std::runtime_error("Cannot load texture: " + texturePath);
    }
    _sprite = sf::Sprite(*_texture);
    sf::Vector2<float> textureSize(_texture->getSize());
    _sprite.setOrigin(textureSize / 2.f);
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
    sf::Vector2<float> spriteScale(_sprite.getScale());
    sf::Rect<int> textureSize(_sprite.getTextureRect());
    sf::Vector2<float> spriteSize(float(textureSize.width) * spriteScale.x, float(textureSize.height) * spriteScale.y);
    sf::Vector2<float> winSize(window.getSize());
    sf::Vector2<float> renderRatio(window.getRenderRatio());
    sf::Vector2<float> newPosition(winSize.x * _position.x, winSize.y * _position.y);
    if (renderRatio.x > renderRatio.y) {
        newPosition.x -= (renderRatio.x - renderRatio.y) * spriteSize.x / 2.f;
    } else if (renderRatio.y > renderRatio.x) {
        newPosition.y -= (renderRatio.y - renderRatio.x) * spriteSize.y / 2.f;
    }
    this->place(newPosition);
}

bool Client::Loader::event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    return false;
}

void Client::Loader::update(Client::Network &network, Client::Window &window)
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

void Client::Loader::adjust(const sf::Vector2<float> &scale)
{
    _sprite.setScale(scale);
}

void Client::Loader::place(const sf::Vector2<float> &position)
{
    _sprite.setPosition(position);
}