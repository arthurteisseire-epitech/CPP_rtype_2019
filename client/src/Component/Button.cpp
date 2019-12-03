/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Menu.cpp
*/

#include "Button.hpp"

Client::Button::Button(uint32_t id, const std::string &texturePath) : _id(id)
{
    sf::Texture texture;
    texture.loadFromFile(texturePath);
    sf::Vector2<int> textureSize(texture.getSize());
    _sprite = sf::Sprite(texture, sf::Rect<int>(0, 0, textureSize.x, textureSize.y / 3));
}

void Client::Button::place(const sf::Vector2f &position)
{
    _sprite.setPosition(position);
}

bool Client::Button::event(Client::Network &network, const Client::KeyBind &keyBind, const sf::Event &event, const sf::Clock &clock)
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

void Client::Button::render(sf::RenderWindow &window)
{
    window.draw(_sprite);
}