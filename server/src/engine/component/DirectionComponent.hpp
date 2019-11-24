/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** DirectionComponent.hpp
*/

#ifndef RTYPE_DIRECTIONCOMPONENT_HPP
#define RTYPE_DIRECTIONCOMPONENT_HPP

namespace ecs
{
    struct DirectionComponent {
        explicit DirectionComponent(int x = 0, int y = 0) :
            x(x),
            y(y)
        {
        }

        int x;
        int y;
    };
}

#endif
