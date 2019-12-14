/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** MainMenu.hpp
*/

#ifndef RTYPE_COMMONCOMPONENT_HPP
#define RTYPE_COMMONCOMPONENT_HPP

#define COMPONENT_ADJUST \
sf::Vector2<float> renderRatio(window.getRenderRatio());\
float referenceRatio = std::max(renderRatio.x, renderRatio.y);\
sf::Vector2<float>newScale(referenceRatio, referenceRatio);\
_sprite.setScale(newScale);\
sf::Rect<int> textureRect(_sprite.getTextureRect());\
sf::Vector2<float> newOrigin(textureRect.width * newScale.x / 2.f, textureRect.height * newScale.y / 2.f);\
_sprite.setOrigin(newOrigin);

#define COMPONENT_PLACE \
sf::Vector2<float> winSize(window.getSize());\
sf::Vector2<float> newPosition(winSize.x * _position.x, winSize.y * _position.y);\
_sprite.setPosition(newPosition);

#define COMPONENT_COLLIDE \
sf::Vector2<float> sprite1Position(this->getPosition());\
sf::Vector2<float> sprite2Position(component->getPosition());\
sf::Vector2<float> sprite1Size(this->getSpriteSize());\
sf::Vector2<float> sprite2Size(component->getSpriteSize());\
sf::Vector2<uint32_t> windowSize(window.getSize());\
return sf::Rect<float>({\
sprite1Position.x * windowSize.x - sprite1Size.x / 2.f,\
sprite1Position.y * windowSize.y - sprite1Size.y / 2.f,\
sprite1Size.x, sprite1Size.y\
}).intersects(sf::Rect<float>({\
    sprite2Position.x * windowSize.x - sprite2Size.x / 2.f,\
    sprite2Position.y * windowSize.y - sprite2Size.y / 2.f,\
    sprite2Size.x, sprite2Size.y\
}));

#define COMPONENT_SPRITE_SIZE \
sf::Rect<int> textureRect(_sprite.getTextureRect());\
sf::Vector2<float> spriteScale(_sprite.getScale());\
return {textureRect.width * spriteScale.x, textureRect.height * spriteScale.y};

#endif