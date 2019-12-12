/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SideScroller.cpp
*/

#include "CommonComponent.hpp"
#include "SideScroller.hpp"

Client::SideScroller::SideScroller(uint8_t layer, const std::string &texturePath, float speed) :
    _layer(layer), _speed(speed), _position({0.5f, 0.5f}), _clock(), _texture(new sf::Texture())
{
    if (!_texture->loadFromFile(ASSETS_DIR + texturePath)) {
        throw std::runtime_error("\'Client::SideScroller::SideScroller\': Cannot load texture: " + texturePath);
    }
    _sprite = sf::Sprite(*_texture);
    _spriteAlt = sf::Sprite(*_texture);
    sf::Vector2<float> textureSize(_texture->getSize());
    _sprite.setOrigin(textureSize / 2.f);
    _spriteAlt.setOrigin(textureSize / 2.f);
}

void Client::SideScroller::move(const sf::Vector2<float> &position)
{
    _position = position;
}

void Client::SideScroller::adjust(Client::Window &window)
{
    COMPONENT_ADJUST
    _spriteAlt.setScale(newScale);
    _spriteAlt.setOrigin(newOrigin);
}

void Client::SideScroller::place(Client::Window &window)
{
    COMPONENT_PLACE
    _spriteAlt.setPosition({newPosition.x + _texture->getSize().x * _sprite.getScale().x, newPosition.y});
}

bool Client::SideScroller::event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    return false;
}

void Client::SideScroller::update(Client::Network &network, Client::Window &window)
{
    float displacement(_clock.getElapsedTime().asSeconds() * _speed);
    displacement -= float(int(displacement));
    this->move({0.5f - displacement, 0.5f});
    this->adjust(window);
    this->place(window);
}

void Client::SideScroller::render(Client::Window &window, uint8_t layer)
{
    if (layer == _layer) {
        window.draw(_sprite);
        window.draw(_spriteAlt);
    }
}

uint32_t Client::SideScroller::getId() const
{
    return 0;
}