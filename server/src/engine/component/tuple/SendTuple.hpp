/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SendTuple.hpp
*/

#ifndef RTYPE_SENDTUPLE_HPP
#define RTYPE_SENDTUPLE_HPP

#include "ObjectPool.hpp"
#include "TransformComponent.hpp"
#include "ConnectionComponent.hpp"

namespace ecs
{
    struct SendTuple {
        SendTuple(ObjectPool<ConnectionComponent>::index connectionIdx,
                  ObjectPool<TransformComponent>::index transformIdx) :
            connectionIdx(connectionIdx),
            transformIdx(transformIdx)
        {
        }

        ObjectPool<ConnectionComponent>::index connectionIdx;
        ObjectPool<TransformComponent>::index transformIdx;
    };
}

#endif
