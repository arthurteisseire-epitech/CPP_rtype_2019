/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SpriteSheet.cpp
*/

#include "CommonComponent.hpp"
#include "SpriteSheet.hpp"

Client::SpriteSheet::SpriteSheet(uint32_t id, uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath, const sf::Vector2<uint32_t> &layout) :
    _id(id), _layer(layer), _position(position), _clock(), _texture(new sf::Texture())
{
    if (!_texture->loadFromFile(ASSETS_DIR + texturePath)) {
        throw std::runtime_error("\'Client::SpriteSheet::SpriteSheet\': Cannot load texture: " + texturePath);
    }
    sf::Vector2<uint32_t> textureSize(_texture->getSize());
    sf::Rect<int> textureRect(0, 0, textureSize.x / layout.x, textureSize.y / layout.y);
    textureRect.left *= textureRect.width;
    textureRect.top *= textureRect.height;
    _sprite = sf::Sprite(*_texture, textureRect);
    _sprite.setOrigin(sf::Vector2<float>(textureRect.width, textureRect.height));
}

void Client::SpriteSheet::move(const sf::Vector2<float> &position)
{
    _position = position;
}

void Client::SpriteSheet::adjust(Client::Window &window)
{
    COMPONENT_ADJUST
}

void Client::SpriteSheet::place(Client::Window &window)
{
    COMPONENT_PLACE
}

bool Client::SpriteSheet::event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    return false;
}

void Client::SpriteSheet::update(Client::Network &network, Client::Window &window)
{
    int clockTime(_clock.getElapsedTime().asMilliseconds());
    sf::Vector2<uint32_t> textureSize(_texture->getSize());
    sf::Rect<int> textureRect(_sprite.getTextureRect());
    sf::Vector2<uint32_t> layout(textureSize.x / textureRect.width, textureSize.y / textureRect.height);
    sf::Vector2<int> textureRectOrigin(clockTime % layout.x, (clockTime / layout.y) % layout.y);
    _sprite.setTextureRect({textureRectOrigin.x * textureRect.width, textureRectOrigin.y * textureRect.height, textureRect.width, textureRect.height});
    this->adjust(window);
    this->place(window);
}

void Client::SpriteSheet::render(Client::Window &window, uint8_t layer)
{
    if (layer == _layer) {
        window.draw(_sprite);
    }
}

uint32_t Client::SpriteSheet::getId() const
{
    return 0;
}