/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CreationBulletTuple.hpp
*/

#ifndef RTYPE_CREATIONBULLETTUPLE_HPP
#define RTYPE_CREATIONBULLETTUPLE_HPP

#include "ObjectPool.hpp"
#include "CCommand.hpp"
#include "CTransform.hpp"
#include "CConnection.hpp"

namespace ecs
{
    using CreationBulletTuple = std::tuple
        <
            ObjectPool<CCommand>::index,
            ObjectPool<CConnection>::index,
            ObjectPool<CTransform>::index
        >;
}

#endif
