/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include "EntityFactory.hpp"
#include "ShootingAISystem.hpp"

#include <utility>
#include "ShootingAITuple.hpp"
#include "CGun.hpp"

ecs::ShootingAISystem::ShootingAISystem(std::shared_ptr<EntityAdmin> admin) :
    ASystem(std::move(admin))
{
}

void ecs::ShootingAISystem::update(float dtime)
{
    ForEachMatching<ShootingAITuple>(admin, [this, dtime](ShootingAITuple &t) {
        auto &gun = get<CGun>(t);
        float &remainingTime = gun.cooldown.remaining;
        remainingTime -= dtime;
        if (remainingTime <= 0) {
            EntityFactory::createEntity(admin,
                                        GetPool<CTransform>(admin).create(get<CTransform>(t).vec),
                                        GetPool<CDirection>(admin).create(CDirection::LEFT),
                                        GetPool<CCollisionDamage>(admin).create(gun.damage),
                                        GetPool<CType>(admin).create(TypeProtocol::get(gun.type.type)),
                                        GetPool<CHealth>(admin).create(gun.health),
                                        GetPool<CSpeed>(admin).create(gun.speed),
                                        GetPool<CMoveType>(admin).create(gun.moveType)
            );
            remainingTime = gun.cooldown.total;
        }
    });
}
