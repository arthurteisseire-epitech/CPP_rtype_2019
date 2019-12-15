/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_SHOOTINGAITUPLE_HPP
#define RTYPE_SHOOTINGAITUPLE_HPP

#include <tuple>
#include "ObjectPool.hpp"
#include "CTransform.hpp"
#include "CDirection.hpp"
#include "CType.hpp"
#include "CGun.hpp"

namespace ecs
{
    using ShootingAITuple = std::tuple
        <
            ObjectPool<CType>::index,
            ObjectPool<CTransform>::index,
            ObjectPool<CGun>::index
        >;
}

#endif
