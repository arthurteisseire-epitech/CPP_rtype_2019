/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include "EntityFactory.hpp"
#include "MonsterSpawningSystem.hpp"
#include "DynamicLoadMonsterSystem.hpp"

ecs::MonsterSpawningSystem::MonsterSpawningSystem(std::shared_ptr<EntityAdmin> admin) :
    ASystem(std::move(admin))
{
}

void ecs::MonsterSpawningSystem::update(float dTime)
{
    for (auto &lib : DynamicLoadMonsterSystem::monsterLibs)
        lib->update(admin, dTime);
}

mut::Vec2f ecs::MonsterSpawningSystem::generateRandomPosition()
{
    return mut::Vec2f(0.9, static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
}
