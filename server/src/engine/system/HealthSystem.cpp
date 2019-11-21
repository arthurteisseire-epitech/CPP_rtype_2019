/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** HealthSystem.cpp
*/

#include "HealthSystem.hpp"

void ecs::HealthSystem::update(float dt, EntityAdmin &admin)
{
    for (auto &c : admin.getPool<HealthComponent>()) {
        if (c.life == 100)
            c.life -= 20;
    }
}
