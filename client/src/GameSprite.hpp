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
#include <functional>

namespace game
{
    class GameSprite {
    public:
        GameSprite();

        enum BasicType {
            SPACESHIP
        };
        enum Type {
            SPACESHIP_NORMAL
        };

        sf::Sprite getSpriteOfType(const Type &type);
        Type getType(const std::string &);

    private:
        static sf::Texture loadTexture(const std::string &filename, const sf::Rect<int> &rect);
        static std::unordered_map<std::string, Type> initTypes();
        static std::unordered_map<BasicType, sf::Texture> initBasicTextures();
        std::unordered_map<Type, std::function<sf::Sprite()>> initSprites();

        const std::unordered_map<std::string, Type> strToType;
        const std::unordered_map<BasicType, sf::Texture> simpleTexture;
        const std::unordered_map<Type, std::function<sf::Sprite()>> typeSprite;
    };
}

#endif
