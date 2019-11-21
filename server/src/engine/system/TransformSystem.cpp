/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** TransformSystem.cpp
*/

#include "TransformSystem.hpp"
#include "TransformComponent.hpp"

void ecs::TransformSystem::update(float dt, EntityAdmin &admin)
{
    for (auto &c : admin.getPool<TransformComponent>()) {
        c.x = 2;
    }
}
