/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** TransformSystem.cpp
*/

#include "TransformSystem.hpp"
#include "TransformComponent.hpp"

ecs::TransformSystem::TransformSystem(std::shared_ptr<EntityAdmin> admin) :
    admin(std::move(admin))
{
}

void ecs::TransformSystem::update(float dt)
{
    for (auto &c : admin->getPool<TransformComponent>().get()) {
        c.x = 2;
    }
}
