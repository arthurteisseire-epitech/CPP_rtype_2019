/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** NotifyPlayerTuple.hpp
*/

#ifndef RTYPE_NOTIFYPLAYERTUPLE_HPP
#define RTYPE_NOTIFYPLAYERTUPLE_HPP

#include "ObjectPool.hpp"
#include "CTransform.hpp"
#include "CConnection.hpp"
#include "CType.hpp"
#include "CId.hpp"

namespace ecs
{
    using NotifyPlayerTuple = std::tuple
        <
            ObjectPool<CTransform>::index,
            ObjectPool<CType>::index,
            ObjectPool<CConnection>::index,
            ObjectPool<CId>::index
        >;
}

#endif
