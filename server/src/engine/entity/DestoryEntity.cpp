/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** DestoryEntity.cpp
*/

#include "EntityUtil.hpp"

void ecs::EntityUtil::DestroyEntity(std::shared_ptr<ecs::EntityAdmin> &admin, unsigned int id)
{
    for (auto &entity: admin->entities)
        if (entity->getId(admin) == id)
            entity->destroy(admin);
}
