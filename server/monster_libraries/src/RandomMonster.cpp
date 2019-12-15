/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include "Util.hpp"
#include "EntityFactory.hpp"
#include "RandomMonster.hpp"

void ecs::RandomMonster::update(std::shared_ptr<EntityAdmin> admin, float deltaTime)
{
    remaining -= deltaTime;
    if (remaining <= 0) {
        EntityFactory::createMonster(admin,
            generateRandomEnemy(),
            GetPool<CDirection>(admin).create(CDirection::LEFT),
            GetPool<CMoveType>(admin).create(CMoveType::STRAIGHT),
            GetPool<CCollisionDamage>(admin).create(20),
            GetPool<CCooldown>(admin).create(5),
            GetPool<CHealth>(admin).create(20),
            GetPool<CGun>(admin).create(generateRandomBullet(), 3),
            GetPool<CSpeed>(admin).create(1));
        remaining = 3;
    }
}

const std::vector<ecs::TypeProtocol::Type> ecs::RandomMonster::enemies = {
    TypeProtocol::ALIEN,
    TypeProtocol::ALIEN2,
    TypeProtocol::ENEMY_SHIP,
    TypeProtocol::ENEMY_SHIP2
};

const std::vector<ecs::CBulletType::BulletType> ecs::RandomMonster::enemiesBullet = {
    CBulletType::VORTEX,
    CBulletType::ENEMY_BASIC
};

ecs::TypeProtocol::Type ecs::RandomMonster::generateRandomEnemy()
{
    return enemies[(rand() % enemies.size())];
}

ecs::CBulletType::BulletType ecs::RandomMonster::generateRandomBullet()
{
    return enemiesBullet[(rand() % enemiesBullet.size())];
}


ecs::AMonster *monsterEntryPoint()
{
    return new ecs::RandomMonster();
}
