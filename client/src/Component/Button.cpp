/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** MainMenu.cpp
*/

#include "Button.hpp"
#include "CommonComponent.hpp"

Client::Button::Button(uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath) :
    _layer(layer), _position(position), _texture(new sf::Texture()), _textureAlt(nullptr)
{
    if (!_texture->loadFromFile(ASSETS_DIR + texturePath)) {
        throw std::runtime_error("\'Client::Button::Button\': Cannot load texture: " + texturePath);
    }
    sf::Vector2<uint32_t> textureSize(_texture->getSize());
    sf::Rect<int> textureRect(0, 0, textureSize.x, textureSize.y / 3);
    _sprite = sf::Sprite(*_texture, textureRect);
    _sprite.setOrigin(sf::Vector2<float>(textureRect.width, textureRect.height));
}

Client::Button::Button(uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath, const std::string &textureAltPath, bool invert) :
    _layer(layer), _position(position), _texture(new sf::Texture()), _textureAlt(new sf::Texture())
{
    if (!_texture->loadFromFile(ASSETS_DIR + texturePath)) {
        throw std::runtime_error("\'Client::Button::Button\': Cannot load texture: " + texturePath);
    } else if (!_textureAlt->loadFromFile(ASSETS_DIR + textureAltPath)) {
        throw std::runtime_error("\'Client::Button::Button\': Cannot load texture: " + textureAltPath);
    }
    sf::Vector2<int> textureSize(_texture->getSize());
    if (textureSize != sf::Vector2<int>(_textureAlt->getSize())) {
        throw std::runtime_error("\'Client::Button::Button\':" + texturePath + " and " + textureAltPath + "are not the same size.");
    }
    sf::Rect<int> textureRect(0, 0, textureSize.x, textureSize.y / 3);
    _sprite = sf::Sprite(invert ? *_textureAlt : *_texture, textureRect);
    _sprite.setOrigin(sf::Vector2<float>(textureRect.width, textureRect.height));
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
    COMPONENT_ADJUST
}

void Client::Button::place(Client::Window &window)
{
    COMPONENT_PLACE
}

bool Client::Button::event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    sf::Vector2<int> mousePos(sf::Mouse::getPosition());
    sf::Vector2<int> buttonPos(_sprite.getPosition());
    sf::Vector2<int> textureSize(_texture->getSize());
    sf::Vector2<float> spriteScale(_sprite.getScale());
    sf::Vector2<int> spriteSize(textureSize.x * spriteScale.x, textureSize.y / 3.f * spriteScale.y);
    sf::Rect<int> buttonRect(0, 0, textureSize.x, textureSize.y / 3);
    bool clicked(false);

    if (buttonRect.contains(mousePos - buttonPos + spriteSize / 2)) {
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