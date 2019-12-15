/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_MOVETUPLE_HPP
#define RTYPE_MOVETUPLE_HPP

#include "ObjectPool.hpp"
#include "CDirection.hpp"
#include "CType.hpp"
#include "CTransform.hpp"
#include "CSpeed.hpp"

namespace ecs
{
    using MoveTuple = std::tuple
        <
            ObjectPool<CType>::index,
            ObjectPool<CTransform>::index,
            ObjectPool<CDirection>::index,
            ObjectPool<CSpeed>::index
        >;
}

#endif
