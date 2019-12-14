/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** PlayerCreationBulletTuple.hpp
*/

#ifndef RTYPE_PLAYERCREATIONBULLETTUPLE_HPP
#define RTYPE_PLAYERCREATIONBULLETTUPLE_HPP

#include "ObjectPool.hpp"
#include "CCommand.hpp"
#include "CTransform.hpp"
#include "CConnection.hpp"

namespace ecs
{
    using PlayerCreationBulletTuple = std::tuple
        <
            ObjectPool<CCommand>::index,
            ObjectPool<CTransform>::index
        >;
}

#endif
