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
            ObjectPool<CConnection>::index,
            ObjectPool<CTransform>::index,
            ObjectPool<CType>::index,
            ObjectPool<CId>::index
        >;
}

#endif
