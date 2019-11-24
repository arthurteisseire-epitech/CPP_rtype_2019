/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** DirectionComponent.hpp
*/

#ifndef RTYPE_DIRECTIONCOMPONENT_HPP
#define RTYPE_DIRECTIONCOMPONENT_HPP

#include <string>
#include <cmath>
#include "Vector2.hpp"

namespace ecs
{
    struct DirectionComponent {
        enum Direction {
            NONE,
            UP,
            DOWN,
            LEFT,
            RIGHT
        };

        explicit DirectionComponent(int x = 0, int y = 0) :
            dir(x, y)
        {
        }

        DirectionComponent &setDirection(const Direction &horizontal, const Direction &vertical)
        {
            float val = horizontal != NONE && vertical != NONE ? M_SQRT2 : 1;

            dir = {0, 0};
            if (horizontal == LEFT)
                dir.x = -val;
            else if (horizontal == RIGHT)
                dir.x = val;
            if (vertical == UP)
                dir.y = val;
            else if (vertical == DOWN)
                dir.y = -val;
            return *this;
        }

        DirectionComponent &setDirection(const DirectionComponent::Direction &dir_enum)
        {
            dir = {0, 0};
            if (dir_enum == LEFT)
                dir.x = -1;
            else if (dir_enum == RIGHT)
                dir.x = 1;
            else if (dir_enum == UP)
                dir.y = 1;
            else if (dir_enum == DOWN)
                dir.y = -1;
            return *this;
        }

        mut::Vec2f dir;
    };
}

#endif
