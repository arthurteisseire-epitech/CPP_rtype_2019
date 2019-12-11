/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** HandleConnectionTuple.hpp
*/

#ifndef RTYPE_HANDLECONNECTIONTUPLE_HPP
#define RTYPE_HANDLECONNECTIONTUPLE_HPP

#include "ObjectPool.hpp"
#include "CCommand.hpp"
#include "CId.hpp"
#include "CConnection.hpp"

namespace ecs
{
    using HandleConnectionTuple = std::tuple
        <
            ObjectPool<CConnection>::index,
            ObjectPool<CCommand>::index,
            ObjectPool<CId>::index
        >;
}

#endif