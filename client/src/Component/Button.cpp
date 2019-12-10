/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** MainMenu.cpp
*/

#include "Button.hpp"

Client::Button::Button(uint32_t id, uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath) :
    _id(id), _layer(layer), _position(position), _texture(new sf::Texture()), _textureAlt(nullptr)
{
    if (!_texture->loadFromFile(ASSETS_DIR + texturePath)) {
        throw std::runtime_error("Cannot load texture: " + texturePath);
    }
    sf::Vector2<int> textureSize(_texture->getSize());
    _sprite = sf::Sprite(*_texture, {0, 0, textureSize.x, textureSize.y / 3});
}

Client::Button::Button(uint32_t id, uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath, const std::string &textureAltPath, bool invert) :
    _id(id), _layer(layer), _position(position), _texture(new sf::Texture()), _textureAlt(new sf::Texture())
{
    if (!_texture->loadFromFile(ASSETS_DIR + texturePath)) {
        throw std::runtime_error("Cannot load texture: " + texturePath);
    } else if (!_textureAlt->loadFromFile(ASSETS_DIR + textureAltPath)) {
        throw std::runtime_error("Cannot load texture: " + textureAltPath);
    }
    sf::Vector2<int> textureSize(_texture->getSize());
    if (textureSize != sf::Vector2<int>(_textureAlt->getSize())) {
        throw std::runtime_error(texturePath + " and " + textureAltPath + "are not the same size.");
    }
    _sprite = sf::Sprite(invert ? *_textureAlt : *_texture, {0, 0, textureSize.x, textureSize.y / 3});
}

Client::Button::~Button()
{
    delete _texture;
}

void Client::Button::move(const sf::Vector2<float> &position)
{
    _position = position;
}

void Client::Button::adjust(Client::Window &window)
{
    sf::Vector2<float> renderRatio(window.getRenderRatio());
    float referenceRatio = std::max(renderRatio.x, renderRatio.y);
    this->adjust({referenceRatio, referenceRatio});
}

void Client::Button::place(Client::Window &window)
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

bool Client::Button::event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    sf::Vector2<int> mousePos(sf::Mouse::getPosition());
    sf::Vector2<int> buttonPos(_sprite.getPosition());
    sf::Vector2<int> textureSize(_texture->getSize());
    sf::Rect<int> buttonRect(0, 0, textureSize.x, textureSize.y / 3);
    bool clicked(false);

    if (buttonRect.contains(mousePos - buttonPos)) {
        buttonRect.top = buttonRect.height;
        if (event.type == sf::Event::MouseButtonPressed ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)) {
            buttonRect.top += buttonRect.height;
        } else if (event.type == sf::Event::MouseButtonReleased ||
            (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter)) {
            this->invert();
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
    this->place(window);
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

void Client::Button::invert()
{
    if (_textureAlt) {
        if (_sprite.getTexture() == _texture) {
            _sprite.setTexture(*_textureAlt);
        } else {
            _sprite.setTexture(*_texture);
        }
    }
}