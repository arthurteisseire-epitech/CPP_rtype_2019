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
            RIGHT,
            LAST
        };

        explicit CDirection(CDirection::Direction dir = NONE)
        {
            setDirection(dir);
        }

        void setDirection(CDirection::Direction dirEnum)
        {
            dir = {0, 0};
            if (dirEnum == LEFT)
                dir.x = -0.01;
            else if (dirEnum == RIGHT)
                dir.x = 0.01;
            else if (dirEnum == UP)
                dir.y = -0.01;
            else if (dirEnum == DOWN)
                dir.y = 0.01;
        }

        void resetDir()
        {
            dir = {0, 0};
        }

        void addDir(CDirection::Direction dirEnum)
        {
            if (dirEnum == LEFT)
                dir.x -= 0.01;
            else if (dirEnum == RIGHT)
                dir.x += 0.01;
            else if (dirEnum == UP)
                dir.y -= 0.01;
            else if (dirEnum == DOWN)
                dir.y += 0.01;
        }

        mut::Vec2f dir;
    };
}

#endif
