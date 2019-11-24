/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include "MoveSystem.hpp"

ecs::MoveSystem::MoveSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(std::move(admin))
{
}

void ecs::MoveSystem::update(float dt)
{
    ;
}
