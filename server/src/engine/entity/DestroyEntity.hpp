/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** DestroyEntity.hpp
*/

#ifndef RTYPE_DESTROYENTITY_HPP
#define RTYPE_DESTROYENTITY_HPP

#include "EntityAdmin.hpp"

namespace ecs
{
    void DestroyEntity(std::shared_ptr<EntityAdmin> &admin, unsigned int id)
    {
        for (auto &entity: admin->entities)
            if (entity->getId(admin) == id)
                entity->destroy(admin);
    }
}

#endif
