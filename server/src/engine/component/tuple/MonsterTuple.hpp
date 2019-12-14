/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_MONSTERTUPLE_HPP
#define RTYPE_MONSTERTUPLE_HPP

#include "CCooldown.hpp"
#include "ObjectPool.hpp"
#include "CType.hpp"
#include "CCollisionDamage.hpp"
#include "CHealth.hpp"
#include "CMoveType.hpp"
#include "CBulletType.hpp"

namespace ecs {
    using MonsterTuple = std::tuple
        <
            ObjectPool<CType>::index,
            ObjectPool<CMoveType>::index,
            ObjectPool<CCollisionDamage>::index,
            ObjectPool<CCooldown>::index,
            ObjectPool<CHealth>::index,
            ObjectPool<CBulletType>::index
        >;
}

#endif //RTYPE_MONSTERTUPLE_HPP
