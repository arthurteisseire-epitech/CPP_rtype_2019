/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** DestroyOOBTuple.hpp
*/

#ifndef RTYPE_DESTROYOOBTUPLE_HPP
#define RTYPE_DESTROYOOBTUPLE_HPP

#include "ObjectPool.hpp"
#include "CId.hpp"
#include "CTransform.hpp"

namespace ecs
{
    using DestroyOOBTuple = std::tuple
        <
            ObjectPool<CId>::index,
            ObjectPool<CTransform>::index
        >;
}

#endif
