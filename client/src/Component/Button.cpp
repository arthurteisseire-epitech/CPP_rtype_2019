/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Menu.cpp
*/

#include "Button.hpp"

Client::Button::Button(uint32_t id, uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath) : _id(id), _layer(layer), _position(position)
{
    sf::Texture texture;
    texture.loadFromFile(texturePath);
    sf::Vector2<uint32_t> textureSize(texture.getSize());
    _sprite = sf::Sprite(texture, sf::Rect<int>(0, 0, textureSize.x, textureSize.y / 3));
}

void Client::Button::adjust(Client::Window &window)
{
    sf::Vector2<float> renderRatio(window.getRenderRatio());
    float referenceRatio = std::max(renderRatio.x, renderRatio.y);
    this->adjust(sf::Vector2<float>(referenceRatio, referenceRatio));
}

void Client::Button::place(const sf::Vector2<float> &ratio, Client::Window &window)
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

bool Client::Button::event(Client::Network &network, Client::KeyBind &keyBind, const sf::Event &event)
{
    sf::Vector2<int> mousePos(sf::Mouse::getPosition());
    sf::Vector2<float> buttonPos(_sprite.getPosition());
    sf::Rect<int> buttonRect(_sprite.getTextureRect());
    bool clicked(false);

    if (buttonRect.contains(mousePos.x - buttonPos.x, mousePos.y - buttonPos.y)) {
        buttonRect.top = buttonRect.height;
        if (event.type == sf::Event::MouseButtonPressed ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)) {
            buttonRect.top += buttonRect.height;
        } else if (event.type == sf::Event::MouseButtonReleased ||
            (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter)) {
            clicked = true;
        }
    } else {
        buttonRect.top = 0;
    }
    _sprite.setTextureRect(buttonRect);
    return clicked;
}

void Client::Button::update(Client::Network &network, Client::Window &window)
{
    this->adjust(window);
    this->place(_position, window);
}

void Client::Button::render(Client::Window &window, uint8_t layer)
{
    if (layer == _layer) {
        window.draw(_sprite);
    }
}

void Client::Button::adjust(const sf::Vector2<float> &scale)
{
    _sprite.setScale(scale);
}

void Client::Button::place(const sf::Vector2<float> &position)
{
    _sprite.setPosition(position);
}