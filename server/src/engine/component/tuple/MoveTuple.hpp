/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_MOVETUPLE_HPP
#define RTYPE_MOVETUPLE_HPP

#include "ObjectPool.hpp"
#include "DirectionComponent.hpp"
#include "TransformComponent.hpp"

namespace ecs
{
    using MoveTuple = std::tuple
        <
            ObjectPool<TransformComponent>::index,
            ObjectPool<DirectionComponent>::index
        >;
}

#endif
