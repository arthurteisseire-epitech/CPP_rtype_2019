/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** InputTuple.hpp
*/

#ifndef RTYPE_INPUTTUPLE_HPP
#define RTYPE_INPUTTUPLE_HPP

#include "ObjectPool.hpp"
#include "DirectionComponent.hpp"
#include "ConnectionComponent.hpp"

namespace ecs
{
    struct InputTuple {
        InputTuple(ObjectPool<ConnectionComponent>::index connectionIdx,
                   ObjectPool<TransformComponent>::index transformidx,
                   ObjectPool<DirectionComponent>::index directionIdx
                   ) :
            connectionIdx(connectionIdx),
            transformIdx(transformidx),
            directionIdx(directionIdx)
        {
        }

        ObjectPool<ConnectionComponent>::index connectionIdx;
        ObjectPool<TransformComponent>::index transformIdx;
        ObjectPool<DirectionComponent>::index directionIdx;
    };
}

#endif
