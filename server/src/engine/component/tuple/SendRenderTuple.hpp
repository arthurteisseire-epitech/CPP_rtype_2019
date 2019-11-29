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
    using SendRenderTuple = std::tuple
        <
            ObjectPool<ConnectionComponent>::index,
            ObjectPool<TransformComponent>::index,
            ObjectPool<TypeComponent>::index,
            ObjectPool<IdComponent>::index
        >;
}

#endif
