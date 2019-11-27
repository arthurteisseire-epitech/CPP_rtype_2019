/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_GAMESPRITE_HPP
#define RTYPE_GAMESPRITE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Image.hpp>
#include <functional>

namespace game
{
    class GameSprite {
    public:
        GameSprite();

        enum BasicType {
            INVALID_BT,

            SPACESHIP,
            BASIC_MISSILE
        };

        enum Type {
            INVALID_T,

            SPACESHIP_RIGHT_MOST,
            SPACESHIP_RIGHT,
            SPACESHIP_NORMAL,
            SPACESHIP_LEFT,
            SPACESHIP_LEFT_MOST,
            SPACESHIP_RIGHT_MOST_REV,
            SPACESHIP_RIGHT_REV,
            SPACESHIP_NORMAL_REV,
            SPACESHIP_LEFT_REV,
            SPACESHIP_LEFT_MOST_REV,

            BASIC_MISSILE_LAUNCH,
            BASIC_MISSILE_LAUNCH_2,
            BASIC_MISSILE_LAUNCHED,
            BASIC_MISSILE_LAUNCHED_REV,
            BASIC_MISSILE_LAUNCH_2_REV,
            BASIC_MISSILE_LAUNCH_REV,
        };

        sf::Sprite getSpriteOfType(const Type &type);
        sf::Sprite getSpriteOfType(const std::string &type);
        Type getType(const std::string &);

    private:
        sf::Texture loadTexture(const std::string &filename, const sf::Rect<int> &rect);
        std::unordered_map<std::string, Type> initTypes();
        std::unordered_map<BasicType, sf::Texture> initBasicTextures();
        std::unordered_map<std::string, sf::Image> initImages();
        std::unordered_map<Type, std::function<sf::Sprite()>> initSprites();

        const std::unordered_map<std::string, Type> strToType;
        const std::unordered_map<std::string, sf::Image> images;
        const std::unordered_map<BasicType, sf::Texture> simpleTexture;
        const std::unordered_map<Type, std::function<sf::Sprite()>> typeSprite;
    };
}

#endif
