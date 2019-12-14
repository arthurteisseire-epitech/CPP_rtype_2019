/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include "Util.hpp"
#include "EntityFactory.hpp"
#include "BasicMonster.hpp"

void ecs::BasicMonster::update(std::shared_ptr<EntityAdmin> admin, float deltaTime)
{
    remaining -= deltaTime;
    if (remaining <= 0) {
        EntityFactory::createMonster(admin, TypeProtocol::SHIP_INVERTED,
            GetPool<CDirection>(admin).create(CDirection::LEFT), GetPool<CMoveType>(admin).create(CMoveType::STRAIGHT),
            GetPool<CCollisionDamage>(admin).create(20), GetPool<CCooldown>(admin).create(5),
            GetPool<CHealth>(admin).create(20), GetPool<CBulletType>(admin).create(CBulletType::BASIC),
            GetPool<CSpeed>(admin).create(2));
        remaining = 2;
    }
}
