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
    struct MoveTuple {
        MoveTuple(ObjectPool<DirectionComponent>::index directionIdx,
                  ObjectPool<TransformComponent>::index transformIdx) :
            directionIdx(directionIdx),
            transformIdx(transformIdx)
        {
        }

        ObjectPool<DirectionComponent>::index directionIdx;
        ObjectPool<TransformComponent>::index transformIdx;
    };
}

#endif
