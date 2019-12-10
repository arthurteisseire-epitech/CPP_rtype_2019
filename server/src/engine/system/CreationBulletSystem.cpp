/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CreationBulletSystem.cpp
*/

#include "CreationBulletSystem.hpp"
#include "CreationBulletTuple.hpp"
#include "EntityFactory.hpp"

ecs::CreationBulletSystem::CreationBulletSystem(std::shared_ptr<EntityAdmin> admin) :
    ASystem(std::move(admin))
{
}

void ecs::CreationBulletSystem::update(float deltaTime)
{
    ForEachMatching<CreationBulletTuple>(admin, [this](CreationBulletTuple &t) {

        auto &inputs = get<CInput>(t).inputs;

        if (std::any_of(inputs.begin(), inputs.end(), isSpace)) {
            EntityFactory::createBullet(admin,
                                        GetIndex<CConnection>(t),
                                        GetPool<CTransform>(admin).create(get<CTransform>(t).vec.x,
                                                                          get<CTransform>(t).vec.y),
                                        GetPool<CDirection>(admin).create(CDirection::RIGHT)
            );
        }
    });
}

bool ecs::CreationBulletSystem::isSpace(CInput::Key input)
{
    return input == CInput::SPACE;
}
