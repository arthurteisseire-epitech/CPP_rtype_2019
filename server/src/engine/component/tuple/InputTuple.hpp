/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** InputTuple.hpp
*/

#ifndef RTYPE_INPUTTUPLE_HPP
#define RTYPE_INPUTTUPLE_HPP

#include "DirectionComponent.hpp"
#include "ConnectionComponent.hpp"

namespace ecs
{
    struct InputTuple {
        InputTuple(ConnectionComponent *connection, DirectionComponent *direction) :
            connection(connection),
            direction(direction)
        {
        }

        ConnectionComponent *connection;
        DirectionComponent *direction;
    };
}

#endif
