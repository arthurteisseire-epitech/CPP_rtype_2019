/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include <iostream>
#include "GameSprite.hpp"

game::GameSprite::GameSprite() :
    strToType(initTypes()),
    images(initImages()),
    simpleTexture(initBasicTextures()),
    typeSprite(initSprites())
{
}

game::GameSprite::Type game::GameSprite::getType(const std::string &str)
{
    auto it = strToType.find(str);

    if (it == strToType.end()) {
        std::cerr << "could not match \"" << str << "\" to a type" << std::endl;
        return INVALID_T;
    }
    return it->second;
}

sf::Sprite game::GameSprite::getSpriteOfType(const game::GameSprite::Type &type)
{
    return typeSprite.at(type)();
}

sf::Sprite game::GameSprite::getSpriteOfType(const std::string &type)
{
    return getSpriteOfType(getType(type));
}

sf::Texture game::GameSprite::loadTexture(const std::string &filename, const sf::Rect<int> &rect)
{
    sf::Texture texture;

    texture.loadFromImage(images.at(filename), rect);
    return texture;
}

std::unordered_map<std::string, game::GameSprite::Type> game::GameSprite::initTypes()
{
    return {
        {"spaceship_right_most", SPACESHIP_RIGHT_MOST},
        {"spaceship_right", SPACESHIP_RIGHT},
        {"spaceship_normal", SPACESHIP_NORMAL},
        {"spaceship_left", SPACESHIP_LEFT},
        {"spaceship_left_most", SPACESHIP_LEFT_MOST},
        {"spaceship_right_most_rev", SPACESHIP_RIGHT_MOST_REV},
        {"spaceship_right_rev", SPACESHIP_RIGHT_REV},
        {"spaceship_normal_rev", SPACESHIP_NORMAL_REV},
        {"spaceship_left_rev", SPACESHIP_LEFT_REV},
        {"spaceship_left_most_rev", SPACESHIP_LEFT_MOST_REV},

        {"basic_missile_launch", BASIC_MISSILE_LAUNCH},
        {"basic_missile_launch_2", BASIC_MISSILE_LAUNCH_2},
        {"basic_missile_launched", BASIC_MISSILE_LAUNCHED},
        {"basic_missile_launched_rev", BASIC_MISSILE_LAUNCHED_REV},
        {"basic_missile_launch_2_rev", BASIC_MISSILE_LAUNCH_2_REV},
        {"basic_missile_launch_rev", BASIC_MISSILE_LAUNCH_REV},
    };
}

std::unordered_map<std::string, sf::Image> game::GameSprite::initImages()
{
    return {
        {
            "../../client/assets/r-typesheet1.gif", [] () {sf::Image image; image.loadFromFile("../../client/assets/r-typesheet1.gif"); return image;}()
        }
    };
}

std::unordered_map<game::GameSprite::BasicType, sf::Texture> game::GameSprite::initBasicTextures()
{
    return {
        {
            SPACESHIP,
            loadTexture("../../client/assets/r-typesheet1.gif", sf::Rect(sf::Vector2<int>(101, 2), sf::Vector2<int>(330, 15)))
        },
        {
            BASIC_MISSILE,
            loadTexture("../../client/assets/r-typesheet1.gif", sf::Rect(sf::Vector2<int>(215, 85), sf::Vector2<int>(102, 12)))
        },
    };
}

std::unordered_map<game::GameSprite::Type, std::function<sf::Sprite()>> game::GameSprite::initSprites()
{
    return {
        {
            INVALID_T,
            [this] () -> sf::Sprite {
                return sf::Sprite();
            }
        },
        {
            SPACESHIP_RIGHT_MOST,
            [this] () -> sf::Sprite {
                return sf::Sprite(this->simpleTexture.at(SPACESHIP), sf::Rect(sf::Vector2<int>(0, 1), sf::Vector2<int>(32, 14)));
            }
        },
        {
            SPACESHIP_RIGHT,
            [this] () -> sf::Sprite {
                return sf::Sprite(this->simpleTexture.at(SPACESHIP), sf::Rect(sf::Vector2<int>(33, 1), sf::Vector2<int>(32, 13)));
            }
        },{
            SPACESHIP_NORMAL,
            [this] () -> sf::Sprite {
                return sf::Sprite(this->simpleTexture.at(SPACESHIP), sf::Rect(sf::Vector2<int>(66, 1), sf::Vector2<int>(32, 12)));
            }
        },{
            SPACESHIP_LEFT,
            [this] () -> sf::Sprite {
                return sf::Sprite(this->simpleTexture.at(SPACESHIP), sf::Rect(sf::Vector2<int>(99, 1), sf::Vector2<int>(32,13)));
            }
        },{
            SPACESHIP_LEFT_MOST,
            [this] () -> sf::Sprite {
                return sf::Sprite(this->simpleTexture.at(SPACESHIP), sf::Rect(sf::Vector2<int>(132, 0), sf::Vector2<int>(32, 14)));
            }
        },{
            SPACESHIP_LEFT_MOST_REV,
            [this] () -> sf::Sprite {
                return sf::Sprite(this->simpleTexture.at(SPACESHIP), sf::Rect(sf::Vector2<int>(166, 0), sf::Vector2<int>(32, 14)));
            }
        },{
            SPACESHIP_LEFT_REV,
            [this] () -> sf::Sprite {
                return sf::Sprite(this->simpleTexture.at(SPACESHIP), sf::Rect(sf::Vector2<int>(299, 1), sf::Vector2<int>(32, 13)));
            }
        },{
            SPACESHIP_NORMAL_REV,
            [this] () -> sf::Sprite {
                return sf::Sprite(this->simpleTexture.at(SPACESHIP), sf::Rect(sf::Vector2<int>(232, 1), sf::Vector2<int>(32, 12)));
            }
        },{
            SPACESHIP_RIGHT_REV,
            [this] () -> sf::Sprite {
                return sf::Sprite(this->simpleTexture.at(SPACESHIP), sf::Rect(sf::Vector2<int>(265, 1), sf::Vector2<int>(32, 13)));
            }
        },{
            SPACESHIP_RIGHT_MOST_REV,
            [this] () -> sf::Sprite {
                return sf::Sprite(this->simpleTexture.at(SPACESHIP), sf::Rect(sf::Vector2<int>(298, 1), sf::Vector2<int>(32, 14)));
            }
        },{
            BASIC_MISSILE_LAUNCH,
            [this] () -> sf::Sprite {
                return sf::Sprite(this->simpleTexture.at(BASIC_MISSILE), sf::Rect(sf::Vector2<int>(0, 0), sf::Vector2<int>(14, 12)));
            }
        },{
            BASIC_MISSILE_LAUNCH_2,
            [this] () -> sf::Sprite {
                return sf::Sprite(this->simpleTexture.at(BASIC_MISSILE), sf::Rect(sf::Vector2<int>(18, 2), sf::Vector2<int>(11, 9)));
            }
        },{
            BASIC_MISSILE_LAUNCHED,
            [this] () -> sf::Sprite {
                return sf::Sprite(this->simpleTexture.at(BASIC_MISSILE), sf::Rect(sf::Vector2<int>(34, 5), sf::Vector2<int>(16, 4)));
            }
        },{
            BASIC_MISSILE_LAUNCHED_REV,
            [this] () -> sf::Sprite {
                return sf::Sprite(this->simpleTexture.at(BASIC_MISSILE), sf::Rect(sf::Vector2<int>(52, 5), sf::Vector2<int>(16, 4)));
            }
        },{
            BASIC_MISSILE_LAUNCH_2_REV,
            [this] () -> sf::Sprite {
                return sf::Sprite(this->simpleTexture.at(BASIC_MISSILE), sf::Rect(sf::Vector2<int>(73, 2), sf::Vector2<int>(11, 9)));
            }
        },{
            BASIC_MISSILE_LAUNCH_REV,
            [this] () -> sf::Sprite {
                return sf::Sprite(this->simpleTexture.at(BASIC_MISSILE), sf::Rect(sf::Vector2<int>(88, 0), sf::Vector2<int>(14, 12)));
            }
        },
    };
}
