/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** EntityAdmin.hpp
*/

#ifndef RTYPE_ENTITYADMIN_HPP
#define RTYPE_ENTITYADMIN_HPP

#include <unordered_map>
#include "ObjectPool.hpp"
#include "HealthComponent.hpp"

namespace ecs
{
    class EntityAdmin {
    public:
        ObjectPool<HealthComponent> &getHealthPool()
        {
            return healthPool;
        };

    private:
        ObjectPool<HealthComponent> healthPool;
    };
}

#endif
