/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** HealthComponent.hpp
*/

#ifndef RTYPE_TRANSFORMCOMPONENT_HPP
#define RTYPE_TRANSFORMCOMPONENT_HPP

namespace ecs
{
    struct TransformComponent {
        explicit TransformComponent(int x = 0, int y = 0) :
            x(x),
            y(y)
        {
        }

        int x;
        int y;
    };
}

#endif
