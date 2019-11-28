/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SendRenderTuple.hpp
*/

#ifndef RTYPE_SENDRENDERTUPLE_HPP
#define RTYPE_SENDRENDERTUPLE_HPP

#include "TransformComponent.hpp"
#include "ConnectionComponent.hpp"
#include "TypeComponent.hpp"
#include "IdComponent.hpp"

namespace ecs
{
    struct SendRenderTuple {
        SendRenderTuple(ConnectionComponent *connection, TransformComponent *transform, TypeComponent *type, IdComponent *id) :
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
