/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** EntityAdmin.hpp
*/

#ifndef RTYPE_ENTITYADMIN_HPP
#define RTYPE_ENTITYADMIN_HPP

#include <unordered_map>
#include <tuple>
#include "ConnectionComponent.hpp"
#include "TransformComponent.hpp"
#include "ObjectPool.hpp"
#include "HealthComponent.hpp"
#include "NetworkComponent.hpp"
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
            ObjectPool<InputTuple>,
            ObjectPool<MoveTuple>
        > pools;
        std::vector<std::unique_ptr<IEntity>> entities;
        NetworkComponent network;
    };
}

#endif
