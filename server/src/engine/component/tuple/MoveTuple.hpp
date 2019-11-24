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
        MoveTuple(DirectionComponent *dir, TransformComponent *transform) : dir(dir), transform(transform) {}

        DirectionComponent *dir;
        TransformComponent *transform;
    };
}

#endif
