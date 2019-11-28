/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SendRenderTuple.hpp
*/

#ifndef RTYPE_SENDRENDERTUPLE_HPP
#define RTYPE_SENDRENDERTUPLE_HPP

#include "ObjectPool.hpp"
#include "TransformComponent.hpp"
#include "ConnectionComponent.hpp"
#include "TypeComponent.hpp"
#include "IdComponent.hpp"

namespace ecs
{
    struct SendRenderTuple {
        SendRenderTuple(ObjectPool<ConnectionComponent>::index connectionIdx,
            ObjectPool<TransformComponent>::index transformIdx,
            ObjectPool<TypeComponent>::index typeIdx,
            ObjectPool<IdComponent>::index idIdx) :
        connectionIdx(connectionIdx),
        transformIdx(transformIdx),
        typeIdx(typeIdx),
        idIdx(idIdx)
        {
        }

        ObjectPool<TransformComponent>::index transformIdx;
        ObjectPool<ConnectionComponent>::index connectionIdx;
        ObjectPool<TypeComponent>::index typeIdx;
        ObjectPool<IdComponent>::index idIdx;
    };
}


#endif
