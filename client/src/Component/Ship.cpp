/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** MainMenu.cpp
*/

#include "Component/CommonComponent.hpp"
#include "Ship.hpp"

static const std::map<sf::Keyboard::Key, std::string> shipAction({
    {sf::Keyboard::Key::Up, PACKET_ACTION_UP},
    {sf::Keyboard::Key::Down, PACKET_ACTION_DOWN},
    {sf::Keyboard::Key::Left, PACKET_ACTION_LEFT},
    {sf::Keyboard::Key::Right, PACKET_ACTION_RIGHT},
    {sf::Keyboard::Key::Space, PACKET_ACTION_SPACE}
});

Client::Ship::Ship(uint32_t id, uint8_t layer, const std::string &texturePath, bool controlled) :
    _id(id), _layer(layer), _controlled(controlled), _life(1.f), _animation({0, 0.f}), _position(0.1f, 0.5f), _texture(new sf::Texture())
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
    _lifeBar.setFillColor({32, 32, 192, 255});
    _lifeBarBack.setFillColor({32, 32, 32, 255});
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
    COMPONENT_ADJUST_LIFEBAR
}

void Client::Ship::place(Client::Window &window)
{
    COMPONENT_PLACE
    COMPONENT_PLACE_LIFEBAR
}

bool Client::Ship::event(const sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    return false;
}

void Client::Ship::update(Client::KeyBind &keyBind, Client::Network &network, Client::Window &window)
{
    if (_controlled) {
        for (auto &action : shipAction) {
            if (sf::Keyboard::isKeyPressed(keyBind.getBind(action.first))) {
                network.send(Client::Packet(action.second, _id).getRaw());
            }
        }
    }
    sf::Rect<int> spriteRect(_sprite.getTextureRect());
    float moveRatio(_sprite.getPosition().y / window.getSize().y - _position.y);
    if (moveRatio != 0) {
        _animation.first = 8;
        _animation.second = moveRatio;
    } else {
        if (_animation.first > 0) {
            _animation.first--;
        }
        if (_animation.first == 0) {
            _animation.second = 0.f;
        }
    }
    spriteRect.left = (2 + 2 * (_animation.second > 0.f) - 2 * (_animation.second < 0.f)) * spriteRect.width;
    _sprite.setTextureRect(spriteRect);
    this->adjust(window);
    this->place(window);
}

void Client::Ship::render(Client::Window &window, uint8_t layer)
{
    if (layer == _layer) {
        window.draw(_sprite);
        window.draw(_lifeBarBack);
        window.draw(_lifeBar);
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

void Client::Ship::setLife(float life)
{
    _life = life;
}