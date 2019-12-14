/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** InputDirectionTuple.hpp
*/

#ifndef RTYPE_COMMANDDIRECTIONTUPLE_HPP
#define RTYPE_COMMANDDIRECTIONTUPLE_HPP

#include "ObjectPool.hpp"
#include "CDirection.hpp"
#include "CCommand.hpp"

namespace ecs
{
    using InputDirectionTuple = std::tuple
        <
            ObjectPool<CDirection>::index,
            ObjectPool<CCommand>::index
        >;
}

#endif
