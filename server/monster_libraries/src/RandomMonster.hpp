/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_RANDOMMONSTER_HPP
#define RTYPE_RANDOMMONSTER_HPP

#include "AMonster.hpp"

namespace ecs
{
    class RandomMonster : public AMonster {
    public:
        void update(std::shared_ptr<EntityAdmin> admin, float deltaTime);

    private:
        float remaining = 0;
        static const std::vector<TypeProtocol::Type> enemies;
        static const std::vector<CBulletType::BulletType> enemiesBullet;

        static TypeProtocol::Type generateRandomEnemy();
        static CBulletType::BulletType generateRandomBullet();
    };
}

extern "C" __attribute__((visibility("default"))) ecs::AMonster *monsterEntryPoint();

#endif
