/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** TransformSystem.cpp
*/

#include "TransformSystem.hpp"
#include "TransformComponent.hpp"
#include "GetPool.hpp"

void ecs::TransformSystem::update(float dt, EntityAdmin &admin)
{
    for (auto &c : GetPool<TransformComponent>(admin)) {
        c.x = 2;
    }
}
