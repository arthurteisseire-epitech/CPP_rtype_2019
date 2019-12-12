/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CollisionTuple.hpp
*/

#ifndef RTYPE_COLLISIONTUPLE_HPP
#define RTYPE_COLLISIONTUPLE_HPP

#include "ObjectPool.hpp"
#include "CId.hpp"
#include "CCollisionDamage.hpp"
#include "CHealth.hpp"

namespace ecs
{
    using CollisionTuple = std::tuple
        <
            ObjectPool<CId>::index,
            ObjectPool<CCollisionDamage>::index,
            ObjectPool<CHealth>::index
        >;
}

#endif
