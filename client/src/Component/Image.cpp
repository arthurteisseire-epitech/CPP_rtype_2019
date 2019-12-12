/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** MainMenu.cpp
*/

#include "CommonComponent.hpp"
#include "Image.hpp"

Client::Image::Image(uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath) :
    _layer(layer), _position(position), _texture(new sf::Texture())
{
    if (!_texture->loadFromFile(ASSETS_DIR + texturePath)) {
        throw std::runtime_error("\'Client::Image::Image\': Cannot load texture: " + texturePath);
    }
    _sprite = sf::Sprite(*_texture);
    _sprite.setOrigin(sf::Vector2<float>(_texture->getSize()) / 2.f);
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
    COMPONENT_ADJUST
}

void Client::Image::place(Client::Window &window)
{
    COMPONENT_PLACE
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