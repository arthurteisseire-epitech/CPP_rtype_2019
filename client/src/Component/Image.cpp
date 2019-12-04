/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Menu.cpp
*/

#include "Image.hpp"

Client::Image::Image(uint32_t id, uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath) : _id(id), _layer(layer), _position(position)
{
    sf::Texture texture;
    texture.loadFromFile(texturePath);
    _sprite = sf::Sprite(texture);
}

void Client::Image::adjust(Client::Window &window)
{
    sf::Vector2<float> renderRatio(window.getRenderRatio());
    float referenceRatio = std::max(renderRatio.x, renderRatio.y);
    this->adjust(sf::Vector2<float>(referenceRatio, referenceRatio));
}

void Client::Image::place(const sf::Vector2<float> &ratio, Client::Window &window)
{
    sf::Vector2<float> spriteScale(_sprite.getScale());
    sf::Vector2<uint32_t> textureSize(_sprite.getTexture()->getSize());
    sf::Vector2<float> spriteSize(float(textureSize.x) * spriteScale.x, float(textureSize.y) / 3. * spriteScale.y);
    sf::Vector2<float> winSize(window.getSize());
    sf::Vector2<float> renderRatio(window.getRenderRatio());
    sf::Vector2<float> newPosition(winSize.x * ratio.x,winSize.y * ratio.y);
    if (renderRatio.x > renderRatio.y) {
        newPosition.x -= (spriteSize.x + (renderRatio.x - renderRatio.y)) / 2;
        newPosition.y -= spriteSize.y / 2;
    } else if (renderRatio.y > renderRatio.x) {
        newPosition.x -= spriteSize.x / 2;
        newPosition.y -= (spriteSize.y + (renderRatio.y - renderRatio.x)) / 2;
    } else {
        newPosition.x -= spriteSize.x / 2;
        newPosition.y -= spriteSize.y / 2;
    }
    this->place(newPosition);
}

bool Client::Image::event(Client::Network &network, Client::KeyBind &keyBind, const sf::Event &event)
{
    return false;
}

void Client::Image::update(Client::Network &network, Client::Window &window)
{
    this->adjust(window);
    this->place(_position, window);
}

void Client::Image::render(Client::Window &window, uint8_t layer)
{
    if (layer == _layer) {
        window.draw(_sprite);
    }
}

void Client::Image::adjust(const sf::Vector2<float> &scale)
{
    _sprite.setScale(scale);
}

void Client::Image::place(const sf::Vector2<float> &position)
{
    _sprite.setPosition(position);
}