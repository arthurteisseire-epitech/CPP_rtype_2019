/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** InputTuple.hpp
*/

#ifndef RTYPE_INPUTTUPLE_HPP
#define RTYPE_INPUTTUPLE_HPP

#include "ObjectPool.hpp"
#include "DirectionComponent.hpp"
#include "ConnectionComponent.hpp"

namespace ecs
{
    using InputTuple = std::tuple
        <
            ObjectPool<ConnectionComponent>::index,
            ObjectPool<TransformComponent>::index,
            ObjectPool<DirectionComponent>::index
        >;
}

#endif
