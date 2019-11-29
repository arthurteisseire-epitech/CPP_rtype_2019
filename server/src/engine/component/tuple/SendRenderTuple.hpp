/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SendRenderTuple.hpp
*/

#ifndef RTYPE_SENDRENDERTUPLE_HPP
#define RTYPE_SENDRENDERTUPLE_HPP

#include "ObjectPool.hpp"
#include "CTransform.hpp"
#include "CConnection.hpp"
#include "CType.hpp"
#include "CId.hpp"

namespace ecs
{
    using SendRenderTuple = std::tuple
        <
            ObjectPool<CConnection>::index,
            ObjectPool<CTransform>::index,
            ObjectPool<CType>::index,
            ObjectPool<CId>::index
        >;
}

#endif
