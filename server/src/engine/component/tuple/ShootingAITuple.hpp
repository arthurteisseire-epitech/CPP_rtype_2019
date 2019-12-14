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
#include "CId.hpp"
#include "CCooldown.hpp"
#include "CBulletType.hpp"

namespace ecs
{
    using ShootingAITuple = std::tuple
        <
            ObjectPool<CId>::index,
            ObjectPool<CType>::index,
            ObjectPool<CTransform>::index,
            ObjectPool<CDirection>::index,
            ObjectPool<CBulletType>::index
        >;
}

#endif
