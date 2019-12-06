/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SendTuple.hpp
*/

#ifndef RTYPE_SENDTUPLE_HPP
#define RTYPE_SENDTUPLE_HPP

#include "ObjectPool.hpp"
#include "CTransform.hpp"
#include "CConnection.hpp"
#include "CType.hpp"
#include "CId.hpp"

namespace ecs
{
    using SendTuple = std::tuple
        <
            const ObjectPool<CConnection>::index,
            const ObjectPool<CTransform>::index,
            const ObjectPool<CType>::index,
            const ObjectPool<CId>::index
        >;
}

#endif
