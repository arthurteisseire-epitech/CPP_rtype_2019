/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CreationBulletSystem.cpp
*/

#include "CreationBulletSystem.hpp"
#include "CreationBulletTuple.hpp"
#include "EntityFactory.hpp"

ecs::CreationBulletSystem::CreationBulletSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(std::move(admin))
{
}

void ecs::CreationBulletSystem::update(float deltaTime)
{
    ForEachMatching<CreationBulletTuple>(admin, [this](CreationBulletTuple &t) {

        auto &inputs = get<CCommand>(t).commands;

        if (ReceiveProtocol::any(ReceiveProtocol::SPACE, inputs)) {
            EntityFactory::createBullet(admin,
                GetPool<CTransform>(admin).create(get<CTransform>(t).vec),
                GetPool<CDirection>(admin).create(CDirection::RIGHT));
        }
    });
}
