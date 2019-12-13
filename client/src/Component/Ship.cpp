/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** MainMenu.cpp
*/

#include "Component/CommonComponent.hpp"
#include "Ship.hpp"

Client::Ship::Ship(uint32_t id, uint8_t layer, const std::string &texturePath, bool controlled) :
    _id(id), _layer(layer), _controlled(controlled), _position(0.1f, 0.5f), _texture(new sf::Texture())
{
    if (!_texture->loadFromFile(ASSETS_DIR + texturePath)) {
        throw std::runtime_error("\'Client::Ship::Ship\': Cannot load texture: " + texturePath);
    }
    sf::Vector2<uint32_t> textureSize(_texture->getSize());
    sf::Rect<int> textureRect(2, controlled ? 0 : 1 + id % 4, textureSize.x / 5, textureSize.y / 5);
    textureRect.left *= textureRect.width;
    textureRect.top *= textureRect.height;
    _sprite = sf::Sprite(*_texture, textureRect);
    _sprite.setOrigin(sf::Vector2<float>(textureRect.width, textureRect.height));
}

Client::Ship::~Ship()
{
    delete _texture;
}

void Client::Ship::move(const sf::Vector2<float> &position)
{
    _position = position;
}

void Client::Ship::adjust(Client::Window &window)
{
    COMPONENT_ADJUST
}

void Client::Ship::place(Client::Window &window)
{
    COMPONENT_PLACE
}

bool Client::Ship::event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    if (_controlled && event.type == sf::Event::KeyPressed && keyBind.isBound(event.key.code)) {
        Client::Packet packet(_id);
        switch (keyBind.getAction(event.key.code)) {
        case sf::Keyboard::Key::Up:
            packet.setPayload(PACKET_ACTION_UP);
            break;
        case sf::Keyboard::Key::Down:
            packet.setPayload(PACKET_ACTION_DOWN);
            break;
        case sf::Keyboard::Key::Left:
            packet.setPayload(PACKET_ACTION_LEFT);
            break;
        case sf::Keyboard::Key::Right:
            packet.setPayload(PACKET_ACTION_RIGHT);
            break;
        case sf::Keyboard::Key::Space:
            packet.setPayload(PACKET_ACTION_SPACE);
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
    try {
        Client::Packet packet(network.findReceived(_id));
        _position = {0, 0};
    } catch (std::runtime_error &packetNotFound) {
        return;
    }
    this->place(window);
    sf::Rect<int> spriteRect(_sprite.getTextureRect());
    float moveRatio(window.getSize().y / _sprite.getPosition().y - _position.y);
    spriteRect.left = (2 + (moveRatio > 0.01) + (moveRatio > 0.02) - (moveRatio < 0.01) - (moveRatio < 0.02)) * spriteRect.width;
    _sprite.setTextureRect(spriteRect);
}

void Client::Ship::render(Client::Window &window, uint8_t layer)
{
    if (layer == _layer) {
        window.draw(_sprite);
    }
}

bool Client::Ship::collide(Client::IComponent *component, Client::Window &window)
{
    COMPONENT_COLLIDE
}

std::string Client::Ship::getIdentity() const
{
    return "ship";
}

uint32_t Client::Ship::getId() const
{
    return _id;
}

sf::Vector2<float> Client::Ship::getPosition() const
{
    return _position;
}

sf::Vector2<float> Client::Ship::getSpriteSize() const
{
    COMPONENT_SPRITE_SIZE
}