/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** MainMenu.cpp
*/

#include "Button.hpp"
#include "CommonComponent.hpp"

Client::Button::Button(uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath) :
    _layer(layer), _position(position), _soundBuffer(), _texture(new sf::Texture()), _textureAlt(nullptr)
{
    if (!_soundBuffer.loadFromFile(ASSETS_DIR + std::string("Menu/Click.ogg"))) {
        throw std::runtime_error("\'Client::Button::Button\': Cannot load sound: Menu/Click.ogg");
    }
    _sound.setBuffer(_soundBuffer);
    if (!_texture->loadFromFile(ASSETS_DIR + texturePath)) {
        throw std::runtime_error("\'Client::Button::Button\': Cannot load texture: " + texturePath);
    }
    sf::Vector2<uint32_t> textureSize(_texture->getSize());
    sf::Rect<int> textureRect(0, 0, textureSize.x, textureSize.y / 3);
    _sprite = sf::Sprite(*_texture, textureRect);
    _sprite.setOrigin(sf::Vector2<float>(textureRect.width, textureRect.height));
}

Client::Button::Button(uint8_t layer, const sf::Vector2<float> &position, const std::string &texturePath, const std::string &textureAltPath, bool invert) :
    _layer(layer), _position(position), _soundBuffer(), _texture(new sf::Texture()), _textureAlt(new sf::Texture())
{
    if (!_soundBuffer.loadFromFile(ASSETS_DIR + std::string("Menu/Click.ogg"))) {
        throw std::runtime_error("\'Client::Button::Button\': Cannot load sound: Menu/Click.ogg");
    }
    _sound.setBuffer(_soundBuffer);
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
    _sound.stop();
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
    sf::Rect<int> buttonRect(_sprite.getTextureRect());
    sf::Vector2<float> spriteScale(_sprite.getScale());
    sf::Vector2<int> spriteSize(buttonRect.width * spriteScale.x, buttonRect.height * spriteScale.y);
    sf::Rect<int> newButtonRect(0, 0, buttonRect.width, buttonRect.height);
    bool clicked(false);

    if (newButtonRect.contains(mousePos - buttonPos + spriteSize / 2)) {
        newButtonRect.top = buttonRect.height;
        if (event.type == sf::Event::MouseButtonPressed ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)) {
            newButtonRect.top += buttonRect.height;
        } else if (event.type == sf::Event::MouseButtonReleased ||
            (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter)) {
            if (window.getSound()) {
                _sound.play();
            }
            this->invert();
            clicked = true;
        }
    }
    _sprite.setTextureRect(newButtonRect);
    return clicked;
}

void Client::Button::update(Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
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

bool Client::Button::collide(Client::IComponent *component, Client::Window &window)
{
    COMPONENT_COLLIDE
}

std::string Client::Button::getIdentity() const
{
    return "button";
}

uint32_t Client::Button::getId() const
{
    return 0;
}

sf::Vector2<float> Client::Button::getPosition() const
{
    return _position;
}

sf::Vector2<float> Client::Button::getSpriteSize() const
{
    COMPONENT_SPRITE_SIZE
}

void Client::Button::setLife(float life)
{
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