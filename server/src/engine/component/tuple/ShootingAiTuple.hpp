/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_SHOOTINGAITUPLE_HPP
#define RTYPE_SHOOTINGAITUPLE_HPP

#include <tuple>
#include <CShootingAI.hpp>
#include "ObjectPool.hpp"
#include "CTransform.hpp"
#include "CDirection.hpp"
#include "CType.hpp"
#include "CId.hpp"

namespace ecs
{
    using ShootingAITuple = std::tuple
        <
            ObjectPool<CTransform>::index,
            ObjectPool<CDirection>::index,
            ObjectPool<CType>::index,
            ObjectPool<CShootingAI>::index,
            ObjectPool<CId>::index
        >;
}

#endif
