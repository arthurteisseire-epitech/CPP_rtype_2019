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

        if (std::any_of(inputs.begin(), inputs.end(), isSpace)) {
            EntityFactory::createBullet(admin,
                GetPool<CTransform>(admin).create(get<CTransform>(t).vec),
                GetPool<CDirection>(admin).create(CDirection::RIGHT));
        }
    });
}

bool ecs::CreationBulletSystem::isSpace(const std::pair<ReceiveProtocol::Key, std::string> &input)
{
    return input.first == ReceiveProtocol::SPACE;
}
