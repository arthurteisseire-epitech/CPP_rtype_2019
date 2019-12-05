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
#include "CTransform.hpp"

namespace ecs
{
    using MoveTuple = std::tuple
        <
            ObjectPool<CTransform>::index,
            const ObjectPool<CDirection>::index
        >;
}

#endif
