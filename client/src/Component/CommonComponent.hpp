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

#endif