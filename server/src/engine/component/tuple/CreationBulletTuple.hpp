/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CreationBulletTuple.hpp
*/

#ifndef RTYPE_CREATIONBULLETTUPLE_HPP
#define RTYPE_CREATIONBULLETTUPLE_HPP

#include "ObjectPool.hpp"
#include "CInput.hpp"
#include "CTransform.hpp"
#include "CConnection.hpp"

namespace ecs
{
    using CreationBulletTuple = std::tuple
        <
            const ObjectPool<CInput>::index,
            const ObjectPool<CConnection>::index,
            const ObjectPool<CTransform>::index
        >;
}

#endif
