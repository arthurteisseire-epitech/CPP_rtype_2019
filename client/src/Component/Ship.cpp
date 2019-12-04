/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Menu.cpp
*/

#include <iostream>
#include "Ship.hpp"

Client::Ship::Ship(uint32_t id, uint8_t layer, const std::string &texturePath, bool controlled) : _id(id), _layer(layer), _controlled(controlled)
{
    sf::Texture texture;
    texture.loadFromFile(texturePath);
    sf::Vector2<int> textureSize(texture.getSize());
    sf::Rect<int> textureRect(2, controlled ? 0 : 1 + id % 4, textureSize.x / 5, textureSize.y / 5);
    textureRect.left *= textureRect.width;
    textureRect.top *= textureRect.height;
    _sprite = sf::Sprite(texture, textureRect);
}

void Client::Ship::adjust(Client::Window &window)
{
    sf::Vector2<float> renderRatio(window.getRenderRatio());
    float referenceRatio = std::max(renderRatio.x, renderRatio.y);
    this->adjust(sf::Vector2<float>(referenceRatio, referenceRatio));
}

void Client::Ship::place(const sf::Vector2<float> &ratio, Client::Window &window)
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

bool Client::Ship::event(Client::Network &network, Client::KeyBind &keyBind, const sf::Event &event)
{
    if (_controlled && event.type == sf::Event::KeyPressed && keyBind.isBound(event.key.code)) {
        Client::Packet packet(_id);
        switch (keyBind.getAction(event.key.code)) {
        case sf::Keyboard::Key::Up:
            packet.setPayload("up");
            break;
        case sf::Keyboard::Key::Down:
            packet.setPayload("down");
            break;
        case sf::Keyboard::Key::Left:
            packet.setPayload("left");
            break;
        case sf::Keyboard::Key::Right:
            packet.setPayload("right");
            break;
        case sf::Keyboard::Key::Space:
            packet.setPayload("space");
            break;
        default:
            return false;
        }
        network.send(packet.getRaw());
        return true;
    }
    return false;
}

void Client::Ship::update(Client::Network &network, Client::Window &window)
{
    this->adjust(window);
    sf::Vector2<float> newPosition;
    try {
        Client::Packet packet(network.findReceived(_id));
        newPosition = {0, 0};
    } catch (std::runtime_error &packetNotFound) {
        return;
    }
    this->place(newPosition, window);
    sf::Rect<int> spriteRect(_sprite.getTextureRect());
    float moveRatio(window.getSize().y / _sprite.getPosition().y - newPosition.y);
    spriteRect.left = (2 + (moveRatio > 0.01) + (moveRatio > 0.02) - (moveRatio < 0.01) - (moveRatio < 0.02)) * spriteRect.width;
    _sprite.setTextureRect(spriteRect);
}

void Client::Ship::render(Client::Window &window, uint8_t layer)
{
    if (layer == _layer) {
        window.draw(_sprite);
    }
}

void Client::Ship::adjust(const sf::Vector2<float> &scale)
{
    _sprite.setScale(scale);
}

void Client::Ship::place(const sf::Vector2<float> &position)
{
    _sprite.setPosition(position);
}