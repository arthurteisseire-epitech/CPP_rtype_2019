/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** HealthSystem.cpp
*/

#include <utility>
#include "HealthSystem.hpp"

ecs::HealthSystem::HealthSystem(std::shared_ptr<EntityAdmin> admin) :
    admin(std::move(admin))
{
}

void ecs::HealthSystem::update(float dt)
{
    for (auto &c : admin->getHealthPool().get()) {
        if (c.life == 100)
            c.life -= 20;
    }
}
