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

namespace ecs
{
    struct EntityAdmin {
        EntityAdmin() :
            network(1234)
        {
        }

        std::tuple<
            ObjectPool<HealthComponent>,
            ObjectPool<TransformComponent>,
            ObjectPool<ConnectionComponent>
        > pools;
        NetworkComponent network;
    };
}

#endif
