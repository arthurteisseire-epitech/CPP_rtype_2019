/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** InputTuple.hpp
*/

#ifndef RTYPE_COMMANDTUPLE_HPP
#define RTYPE_COMMANDTUPLE_HPP

#include "ObjectPool.hpp"
#include "CCommand.hpp"
#include "CConnection.hpp"

namespace ecs
{
    using CommandTuple = std::tuple
        <
            ObjectPool<CConnection>::index,
            ObjectPool<CCommand>::index
        >;
}

#endif
