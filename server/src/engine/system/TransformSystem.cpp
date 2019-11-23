/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** TransformSystem.cpp
*/

#include "TransformSystem.hpp"
#include "TransformComponent.hpp"
#include "GetPool.hpp"

ecs::TransformSystem::TransformSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(std::move(admin))
{
}

void ecs::TransformSystem::update(float dt)
{
    for (auto &c : GetPool<TransformComponent>(admin)) {
        c.x = 2;
    }
}
