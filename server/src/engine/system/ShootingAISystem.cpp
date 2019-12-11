/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include "EntityFactory.hpp"
#include "ShootingAISystem.hpp"

ecs::ShootingAISystem::ShootingAISystem(std::shared_ptr<EntityAdmin> admin) : ASystem(admin)
{
}

void ecs::ShootingAISystem::update(float dtime)
{
    ForEachMatching<ShootingAITuple>(admin, [this, dtime](ShootingAITuple &t) {
        float &remainingTime = get<CCooldown>(t).remaining;
        remainingTime -= dtime;
        if (remainingTime <= 0) {
            EntityFactory::createBullet(admin,
                GetPool<CTransform>(admin).create(get<CTransform>(t).vec),
                GetPool<CDirection>(admin).create(CDirection::LEFT));
            remainingTime = get<CCooldown>(t).total;
        }
    });
}
