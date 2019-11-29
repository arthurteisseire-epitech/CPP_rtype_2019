/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CDirection.hpp
*/

#ifndef RTYPE_CDIRECTION_HPP
#define RTYPE_CDIRECTION_HPP

#include <string>
#include <cmath>
#include "Vector2.hpp"

namespace ecs
{
    struct CDirection {
        enum Direction {
            NONE,
            UP,
            DOWN,
            LEFT,
            RIGHT
        };

        explicit CDirection(int x = 0, int y = 0) :
            dir(x, y)
        {
        }

        CDirection &setDirection(const Direction &horizontal, const Direction &vertical)
        {
            float val = horizontal != NONE && vertical != NONE ? M_SQRT2 : 1;

            if (horizontal == LEFT)
                dir.x -= val;
            else if (horizontal == RIGHT)
                dir.x += val;
            if (vertical == UP)
                dir.y -= val;
            else if (vertical == DOWN)
                dir.y += val;
            return *this;
        }

        CDirection &setDirection(const CDirection::Direction &dir_enum)
        {
            if (dir_enum == LEFT)
                dir.x -= 1;
            else if (dir_enum == RIGHT)
                dir.x += 1;
            else if (dir_enum == UP)
                dir.y -= 1;
            else if (dir_enum == DOWN)
                dir.y += 1;
            return *this;
        }

        mut::Vec2f dir;
    };
}

#endif
