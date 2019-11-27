/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include "GameSprite.hpp"

game::GameSprite::GameSprite() :
    strToType(initTypes()),
    simpleTexture(initBasicTextures()),
    typeSprite(initSprites())
{
}

game::GameSprite::Type game::GameSprite::getType(const std::string &str)
{
    return strToType.at(str);
}

sf::Sprite game::GameSprite::getSpriteOfType(const game::GameSprite::Type &type)
{
    return typeSprite.at(type)();
}

sf::Texture game::GameSprite::loadTexture(const std::string &filename, const sf::Rect<int> &rect)
{
    sf::Texture texture;
    texture.loadFromFile(filename, rect);
    return texture;
}

std::unordered_map<std::string, game::GameSprite::Type> game::GameSprite::initTypes()
{
    return {{"spaceship_normal", SPACESHIP_NORMAL}};
}

std::unordered_map<game::GameSprite::BasicType, sf::Texture> game::GameSprite::initBasicTextures()
{
    return {{SPACESHIP, loadTexture("../../client/assets/r-typesheet1.gif", sf::Rect(sf::Vector2<int>(101, 2), sf::Vector2<int>(330, 15)))}};
}

std::unordered_map<game::GameSprite::Type, std::function<sf::Sprite()>> game::GameSprite::initSprites()
{
    return {
        {
            SPACESHIP_NORMAL,
            [this] () -> sf::Sprite {
                return sf::Sprite(this->simpleTexture.at(SPACESHIP), sf::Rect(sf::Vector2<int>(0, 1), sf::Vector2<int>(32,14)));
            }
        }
    };
}

