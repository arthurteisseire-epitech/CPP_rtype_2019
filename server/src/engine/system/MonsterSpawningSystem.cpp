/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include "EntityFactory.hpp"
#include "MonsterSpawningSystem.hpp"

ecs::MonsterSpawningSystem::MonsterSpawningSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(admin)
{
}

void ecs::MonsterSpawningSystem::update(float dTime)
{
    timeSinceLastSpawn += dTime;
    if (timeSinceLastSpawn > 2) {
        EntityFactory::createShootingMonster(admin, GetPool<CTransform>(admin).create(generateRandomPosition()),
            GetPool<CDirection>(admin).create(CDirection::LEFT));
        timeSinceLastSpawn = 0;
    }
}

mut::Vec2f ecs::MonsterSpawningSystem::generateRandomPosition()
{
    return mut::Vec2f(1.0, static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
}
