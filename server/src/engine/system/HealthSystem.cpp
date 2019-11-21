/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** HealthSystem.cpp
*/

#include "HealthSystem.hpp"
#include "GetPool.hpp"

void ecs::HealthSystem::update(float dt, EntityAdmin &admin)
{
    for (auto &c : GetPool<HealthComponent>(admin)) {
        if (c.life == 100)
            c.life -= 20;
    }
}
