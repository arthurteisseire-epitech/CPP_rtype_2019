/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_MOVETUPLE_HPP
#define RTYPE_MOVETUPLE_HPP

#include "DirectionComponent.hpp"
#include "TransformComponent.hpp"

namespace ecs
{
    struct MoveTuple {
        MoveTuple(DirectionComponent *direction, TransformComponent *transform) :
            direction(direction),
            transform(transform)
        {
        }

        DirectionComponent *direction;
        TransformComponent *transform;
    };
}

#endif
