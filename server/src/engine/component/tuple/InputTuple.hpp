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
        InputTuple(ConnectionComponent *connection, TransformComponent *transform, DirectionComponent *direction) :
            connection(connection),
            transform(transform),
            direction(direction)
        {
        }

        ConnectionComponent *connection;
        TransformComponent *transform;
        DirectionComponent *direction;
    };
}

#endif
