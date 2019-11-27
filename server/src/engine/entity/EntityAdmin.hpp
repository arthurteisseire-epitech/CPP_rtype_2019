/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** EntityAdmin.hpp
*/

#ifndef RTYPE_ENTITYADMIN_HPP
#define RTYPE_ENTITYADMIN_HPP

#include <tuple>
#include "SendTuple.hpp"
#include "ConnectionComponent.hpp"
#include "TransformComponent.hpp"
#include "ObjectPool.hpp"
#include "HealthComponent.hpp"
#include "NetworkComponent.hpp"
#include "TypeComponent.hpp"
#include "IdComponent.hpp"
#include "MoveTuple.hpp"
#include "InputTuple.hpp"
#include "IEntity.hpp"

namespace ecs
{
    struct EntityAdmin {
        EntityAdmin() :
            network(1234)
        {
        }

        std::tuple<
            ObjectPool<ConnectionComponent>,
            ObjectPool<DirectionComponent>,
            ObjectPool<TransformComponent>,
            ObjectPool<TypeComponent>,
            ObjectPool<IdComponent>,
            ObjectPool<InputTuple>,
            ObjectPool<SendTuple>,
            ObjectPool<MoveTuple>
        > pools;
        std::vector<std::unique_ptr<IEntity>> entities;
        NetworkComponent network;
    };
}

#endif
