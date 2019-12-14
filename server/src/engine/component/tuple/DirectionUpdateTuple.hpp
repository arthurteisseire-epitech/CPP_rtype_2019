/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_DIRECTIONUPDATETUPLE_HPP
#define RTYPE_DIRECTIONUPDATETUPLE_HPP

#include "ObjectPool.hpp"
#include "CMoveType.hpp"
#include "CDirection.hpp"

namespace ecs
{
    using DirectionUpdateTuple = std::tuple
        <
            ObjectPool<CDirection>::index,
            ObjectPool<CMoveType>::index
        >;
}

#endif //RTYPE_DIRECTIONUPDATETUPLE_HPP
