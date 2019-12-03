/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Menu.cpp
*/

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

void Client::Ship::place(const sf::Vector2f &position)
{
    _sprite.setPosition(position);
}

bool Client::Ship::event(Client::Network &network, const Client::KeyBind &keyBind, const sf::Event &event, const sf::Clock &clock)
{
    if (_controlled && event.type == sf::Event::KeyPressed && keyBind.isBinded(event.key.code)) {
        switch (keyBind.getAction(event.key.code)) {
        case sf::Keyboard::Key::Up:
            network.send("up", 2);
            break;
        case sf::Keyboard::Key::Down:
            network.send("down", 4);
            break;
        case sf::Keyboard::Key::Left:
            network.send("left", 4);
            break;
        case sf::Keyboard::Key::Right:
            network.send("right", 5);
            break;
        case sf::Keyboard::Key::Space:
            network.send("space", 5);
            break;
        default:
            break;
        }
    }
    return false;
}

void Client::Ship::render(sf::RenderWindow &window)
{
    window.draw(_sprite);
}