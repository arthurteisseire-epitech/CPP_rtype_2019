/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include "MoveSystem.hpp"
#include "MoveTuple.hpp"
#include "GetPool.hpp"

ecs::MoveSystem::MoveSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(std::move(admin))
{
}

void ecs::MoveSystem::update(float dt)
{
    for (auto &moveComponent : GetPool<MoveTuple>(admin))
        moveComponent.transform->vec += moveComponent.dir->dir;
}
