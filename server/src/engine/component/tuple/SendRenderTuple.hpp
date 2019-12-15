/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SendTuple.hpp
*/

#ifndef RTYPE_SENDRENDERTUPLE_HPP
#define RTYPE_SENDRENDERTUPLE_HPP

#include "ObjectPool.hpp"
#include "CTransform.hpp"
#include "CConnection.hpp"
#include "CType.hpp"
#include "CHealth.hpp"
#include "CId.hpp"

namespace ecs
{
    using SendTuple = std::tuple
        <
            ObjectPool<CTransform>::index,
            ObjectPool<CType>::index,
            ObjectPool<CHealth>::index,
            ObjectPool<CId>::index
        >;
}

#endif
