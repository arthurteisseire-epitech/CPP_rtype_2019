/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CreationBulletSystem.cpp
*/

#include "CreationBulletSystem.hpp"
#include "PlayerCreationBulletTuple.hpp"
#include "EntityFactory.hpp"

ecs::CreationBulletSystem::CreationBulletSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(std::move(admin))
{
}

void ecs::CreationBulletSystem::update(float deltaTime)
{
    ForEachMatching<PlayerCreationBulletTuple>(admin, [this](PlayerCreationBulletTuple &t) {

        auto &commands = get<CCommand>(t).commands;

        if (std::any_of(commands.begin(), commands.end(), isSpace)) {
            EntityFactory::createBullet(admin,
                GetPool<CTransform>(admin).create(get<CTransform>(t).vec),
                GetPool<CDirection>(admin).create(CDirection::RIGHT));
        }
    });
}

bool ecs::CreationBulletSystem::isSpace(const std::pair<ReceiveProtocol::Key, std::string> &pair)
{
    return pair.first == ReceiveProtocol::SPACE;
}
