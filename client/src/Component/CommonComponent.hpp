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
this->adjust({referenceRatio, referenceRatio});

#define COMPONENT_PLACE \
sf::Vector2<float> spriteScale(_sprite.getScale());\
sf::Rect<int> textureSize(_sprite.getTextureRect());\
sf::Vector2<float> spriteSize(float(textureSize.width) * spriteScale.x, float(textureSize.height) * spriteScale.y);\
sf::Vector2<float> winSize(window.getSize());\
sf::Vector2<float> renderRatio(window.getRenderRatio());\
sf::Vector2<float> newPosition(winSize.x * _position.x, winSize.y * _position.y);\
if (renderRatio.x > renderRatio.y) {\
    newPosition.x -= (spriteSize.x + (renderRatio.x - renderRatio.y) * spriteSize.x) / 2.f;\
    newPosition.y -= spriteSize.y / 2.f;\
} else if (renderRatio.y > renderRatio.x) {\
    newPosition.x -= spriteSize.x / 2.f;\
    newPosition.y -= (spriteSize.y + (renderRatio.y - renderRatio.x) * spriteSize.y) / 2.f;\
} else {\
    newPosition.x -= spriteSize.x / 2.f;\
    newPosition.y -= spriteSize.y / 2.f;\
}\
this->place(newPosition);

#endif