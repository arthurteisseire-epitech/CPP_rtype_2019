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

        auto &inputs = get<CInput>(t).inputs;
        for (auto &input : inputs) {
            if (get<CInput>(t).inputs.front() == CInput::SPACE) {
                EntityFactory::createBullet(admin,
                    GetIndex<CConnection>(t),
                    GetPool<CTransform>(admin).create(get<CTransform>(t).vec.x, get<CTransform>(t).vec.y),
                    GetPool<CDirection>(admin).create(CDirection::RIGHT)
                );
            }
        }
        inputs.erase(std::remove(inputs.begin(), inputs.end(), CInput::SPACE), inputs.end());
    });
}
