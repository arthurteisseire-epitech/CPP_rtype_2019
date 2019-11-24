/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** DirectionComponent.hpp
*/

#ifndef RTYPE_DIRECTIONCOMPONENT_HPP
#define RTYPE_DIRECTIONCOMPONENT_HPP

#include "Vector2.hpp"

namespace ecs
{
    struct DirectionComponent {
        explicit DirectionComponent(int x = 0, int y = 0) :
            dir(x, y)
        {
        }

        mut::Vec2f dir;
    };
}

#endif
