/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** HealthComponent.hpp
*/

#ifndef RTYPE_TRANSFORMCOMPONENT_HPP
#define RTYPE_TRANSFORMCOMPONENT_HPP

#include "Vector2.hpp"

namespace ecs
{
    struct TransformComponent {
        explicit TransformComponent(int x = 0, int y = 0) : vec(x, y)
        {
        }

        mut::Vec2f vec;
    };
}

#endif
