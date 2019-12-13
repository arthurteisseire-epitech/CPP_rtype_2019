/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Entity.cpp
*/

#include "CommonComponent.hpp"
#include "Entity.hpp"

Client::Entity::Entity(uint32_t id, uint8_t layer, const std::string &identity, const sf::Vector2<float> &position, const std::string &texturePath, const sf::Vector2<uint32_t> &layout) :
    _id(id), _layer(layer), _identity(identity), _position(position), _clock(), _texture(new sf::Texture())
{
    if (!_texture->loadFromFile(ASSETS_DIR + texturePath)) {
        throw std::runtime_error("\'Client::Entity::Entity\': Cannot load texture: " + texturePath);
    }
    sf::Vector2<uint32_t> textureSize(_texture->getSize());
    sf::Rect<int> textureRect(0, 0, textureSize.x / layout.x, textureSize.y / layout.y);
    textureRect.left *= textureRect.width;
    textureRect.top *= textureRect.height;
    _sprite = sf::Sprite(*_texture, textureRect);
    _sprite.setOrigin(sf::Vector2<float>(textureRect.width, textureRect.height));
}

void Client::Entity::move(const sf::Vector2<float> &position)
{
    _position = position;
}

void Client::Entity::adjust(Client::Window &window)
{
    COMPONENT_ADJUST
}

void Client::Entity::place(Client::Window &window)
{
    COMPONENT_PLACE
}

bool Client::Entity::event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    return false;
}

void Client::Entity::update(Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
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

void Client::Entity::render(Client::Window &window, uint8_t layer)
{
    if (layer == _layer) {
        window.draw(_sprite);
    }
}

bool Client::Entity::collide(Client::IComponent *component, Client::Window &window)
{
    COMPONENT_COLLIDE
}

std::string Client::Entity::getIdentity() const
{
    return _identity;
}

uint32_t Client::Entity::getId() const
{
    return _id;
}

sf::Vector2<float> Client::Entity::getPosition() const
{
    return _position;
}

sf::Vector2<float> Client::Entity::getSpriteSize() const
{
    COMPONENT_SPRITE_SIZE
}