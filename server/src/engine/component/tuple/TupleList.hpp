/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** TupleList.hpp
*/

#ifndef RTYPE_TUPLELIST_HPP
#define RTYPE_TUPLELIST_HPP

#include "MoveTuple.hpp"
#include "CommandTuple.hpp"
#include "SendTuple.hpp"
#include "CreationBulletTuple.hpp"
#include "CommandDirectionTuple.hpp"

namespace ecs
{
    using TupleList = std::tuple
        <
            MoveTuple,
            InputTuple,
            SendTuple,
            CreationBulletTuple,
            InputDirectionTuple
        >;
}

#endif
