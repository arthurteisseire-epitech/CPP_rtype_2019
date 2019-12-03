/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Menu.cpp
*/

#include <iostream>
#include "Ship.hpp"

Client::Ship::Ship(uint32_t id, const std::string &texturePath, bool controlled) : _id(id), _controlled(controlled)
{
    sf::Texture texture;
    texture.loadFromFile(texturePath);
    sf::Vector2<int> textureSize(texture.getSize());
    sf::Rect<int> textureRect(2, controlled ? 0 : 1 + id % 4, textureSize.x / 5, textureSize.y / 5);
    textureRect.left *= textureRect.width;
    textureRect.top *= textureRect.height;
    _sprite = sf::Sprite(texture, textureRect);
}

void Client::Ship::place(const sf::Vector2<float> &position)
{
    _sprite.setPosition(position);
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

void Client::Ship::render(Client::Network &network, sf::RenderWindow &window)
{
    try {
        Client::Packet packet(network.findReceived(_id));
        sf::Vector2<float> newPosition(_sprite.getPosition());
        this->place(newPosition);
        sf::Rect<int> spriteRect(_sprite.getTextureRect());
        float moveRatio(float(window.getSize().y) / (_sprite.getPosition().y - newPosition.y));
        if (moveRatio < 0) { //Ship is going downward
            spriteRect.left = (2 - (moveRatio < 0.01) - (moveRatio < 0.02)) * spriteRect.width;
        } else { //Ship is going upward
            spriteRect.left = (2 + (moveRatio > 0.01) + (moveRatio > 0.02)) * spriteRect.width;
        }
        _sprite.setTextureRect(spriteRect);
    } catch (std::runtime_error &packetNotFound) {}
    window.draw(_sprite);
}