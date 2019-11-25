/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SendTuple.hpp
*/

#ifndef RTYPE_SENDTUPLE_HPP
#define RTYPE_SENDTUPLE_HPP

#include "TransformComponent.hpp"
#include "ConnectionComponent.hpp"

namespace ecs
{
    struct SendTuple {
        explicit SendTuple(ConnectionComponent *connection, TransformComponent *transform) :
            connection(connection),
            transform(transform)
        {
        }

        ConnectionComponent *connection;
        TransformComponent *transform;
    };
}

#endif
