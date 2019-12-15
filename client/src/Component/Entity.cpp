/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Entity.cpp
*/

#include "CommonComponent.hpp"
#include "Entity.hpp"

Client::Entity::Entity(uint32_t id, uint8_t layer, const std::string &identity, const sf::Vector2<float> &position, const std::pair<std::string, std::string> &assetsPath, const sf::Vector2<uint32_t> &layout, bool hasLife) :
    _id(id), _layer(layer), _life(hasLife ? 1.f : -1.f), _identity(identity), _position(position), _clock(), _soundPlayed(false), _soundBuffer(assetsPath.first.empty() ? nullptr : new sf::SoundBuffer()), _texture(new sf::Texture())
{
    if (_soundBuffer) {
        if (!_soundBuffer->loadFromFile(ASSETS_DIR + assetsPath.first)) {
            throw std::runtime_error("\'Client::Button::Button\': Cannot load sound: " + assetsPath.first);
        }
        _sound.setBuffer(*_soundBuffer);
    }
    if (!_texture->loadFromFile(ASSETS_DIR + assetsPath.second)) {
        throw std::runtime_error("\'Client::Entity::Entity\': Cannot load texture: " + assetsPath.second);
    }
    sf::Vector2<uint32_t> textureSize(_texture->getSize());
    sf::Rect<int> textureRect(0, 0, textureSize.x / layout.x, textureSize.y / layout.y);
    textureRect.left *= textureRect.width;
    textureRect.top *= textureRect.height;
    _sprite = sf::Sprite(*_texture, textureRect);
    _sprite.setOrigin(sf::Vector2<float>(textureRect.width, textureRect.height));
    if (hasLife) {
        _lifeBar.setFillColor({192, 32, 32, 255});
        _lifeBarBack.setFillColor({32, 32, 32, 255});
    }
}

Client::Entity::~Entity()
{
    _sound.stop();
    delete _soundBuffer;
    delete _texture;
}

void Client::Entity::move(const sf::Vector2<float> &position)
{
    _position = position;
}

void Client::Entity::adjust(Client::Window &window)
{
    COMPONENT_ADJUST
    if (_life > 0.f) {
        COMPONENT_ADJUST_LIFEBAR
    }
}

void Client::Entity::place(Client::Window &window)
{
    COMPONENT_PLACE
    if (_life > 0.f) {
        COMPONENT_PLACE_LIFEBAR
    }
}

bool Client::Entity::event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    return false;
}

void Client::Entity::update(Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    if (!_soundPlayed && _soundBuffer) {
        if (window.getSound()) {
            _sound.play();
        }
        _soundPlayed = true;
    }
    int clockTime(_clock.getElapsedTime().asMilliseconds() / 200);
    sf::Vector2<uint32_t> textureSize(_texture->getSize());
    sf::Rect<int> textureRect(_sprite.getTextureRect());
    sf::Vector2<uint32_t> layout(textureSize.x / textureRect.width, textureSize.y / textureRect.height);
    sf::Vector2<int> textureRectOrigin(clockTime % layout.x, (clockTime / layout.y) % layout.y);
    _sprite.setTextureRect({textureRectOrigin.x * textureRect.width, textureRectOrigin.y * textureRect.height, textureRect.width, textureRect.height});
    this->adjust(window);
    this->place(window);
}

void Client::Entity::render(Client::Window &window, uint8_t layer)
{
    if (layer == _layer) {
        window.draw(_sprite);
        if (_life > 0.f) {
            window.draw(_lifeBarBack);
            window.draw(_lifeBar);
        }
    }
}

bool Client::Entity::collide(Client::IComponent *component, Client::Window &window)
{
    COMPONENT_COLLIDE
}

std::string Client::Entity::getIdentity() const
{
    return _identity;
}

uint32_t Client::Entity::getId() const
{
    return _id;
}

sf::Vector2<float> Client::Entity::getPosition() const
{
    return _position;
}

sf::Vector2<float> Client::Entity::getSpriteSize() const
{
    COMPONENT_SPRITE_SIZE
}

void Client::Entity::setLife(float life)
{
    if (_life > 0.f) {
        _life = life;
    }
}