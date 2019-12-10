/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** MainMenu.cpp
*/

#include "Image.hpp"

Client::Image::Image(uint32_t id, uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath) :
    _id(id), _layer(layer), _position(position), _texture(new sf::Texture())
{
    if (!_texture->loadFromFile(ASSETS_DIR + texturePath)) {
        throw std::runtime_error("Cannot load texture: " + texturePath);
    }
    _sprite = sf::Sprite(*_texture);
}

Client::Image::~Image()
{
    delete _texture;
}

void Client::Image::move(const sf::Vector2<float> &position)
{
    _position = position;
}

void Client::Image::adjust(Client::Window &window)
{
    sf::Vector2<float> renderRatio(window.getRenderRatio());
    float referenceRatio = std::max(renderRatio.x, renderRatio.y);
    this->adjust({referenceRatio, referenceRatio});
}

void Client::Image::place(Client::Window &window)
{
    sf::Vector2<float> spriteScale(_sprite.getScale());
    sf::Rect<int> textureSize(_sprite.getTextureRect());
    sf::Vector2<float> spriteSize(float(textureSize.width) * spriteScale.x, float(textureSize.height) * spriteScale.y);
    sf::Vector2<float> winSize(window.getSize());
    sf::Vector2<float> renderRatio(window.getRenderRatio());
    sf::Vector2<float> newPosition(winSize.x * _position.x, winSize.y * _position.y);
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

bool Client::Image::event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    return false;
}

void Client::Image::update(Client::Network &network, Client::Window &window)
{
    this->adjust(window);
    this->place(window);
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