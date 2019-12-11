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

        explicit CDirection(CDirection::Direction dir = NONE)
        {
            setDirection(dir);
        }

        void setDirection(CDirection::Direction dir_enum)
        {
            if (dir_enum == LEFT)
                dir.x = -0.01;
            else if (dir_enum == RIGHT)
                dir.x = 0.01;
            else if (dir_enum == UP)
                dir.y = -0.01;
            else if (dir_enum == DOWN)
                dir.y = 0.01;
            if (dir_enum == NONE) {
                dir.x = 0;
                dir.y = 0;
            }
        }

        mut::Vec2f dir;
    };
}

#endif
