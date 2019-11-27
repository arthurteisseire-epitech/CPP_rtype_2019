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
#include "TypeComponent.hpp"
#include "IdComponent.hpp"

namespace ecs
{
    struct SendTuple {
        SendTuple(ConnectionComponent *connection, TransformComponent *transform, TypeComponent *type, IdComponent *id) :
            connection(connection),
            transform(transform),
            type(type),
            id(id)
        {
        }

        ConnectionComponent *connection;
        const TransformComponent *transform;
        const TypeComponent *type;
        const IdComponent *id;
    };
}

#endif
