/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** HealthSystem.cpp
*/

#include "HealthSystem.hpp"
#include "GetPool.hpp"

ecs::HealthSystem::HealthSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(std::move(admin))
{
}

void ecs::HealthSystem::update(float dt)
{
    for (auto &c : GetPool<HealthComponent>(admin)) {
        if (c.life == 100)
            c.life -= 20;
    }
}
