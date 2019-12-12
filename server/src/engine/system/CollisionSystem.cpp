/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CollisionSystem.cpp
*/

#include <utility>
#include "TypeProtocol.hpp"
#include "CollisionSystem.hpp"

ecs::CollisionSystem::CollisionSystem(std::shared_ptr<EntityAdmin> admin) :
    ASystem(std::move(admin))
{
}

void ecs::CollisionSystem::update(float dt)
{
    ForEachMatching<CCommand>(admin, std::bind(&CollisionSystem::updateTuple, this, std::placeholders::_1));
}

void ecs::CollisionSystem::updateTuple(CCommand &t)
{
    for (auto &command : t.commands) {
        if (isCollision(command)) {
            try {
                handleCollision(command);
            } catch (...) {
            }
        }
    }
}

void ecs::CollisionSystem::handleCollision(const std::pair<ReceiveProtocol::Key, std::string> &command)
{
    unsigned int id1 = std::stoi(command.second.substr(0, command.second.find(';')));
    unsigned int id2 = std::stoi(command.second.substr(command.second.find(';') + 1));

    auto t1 = GetById<CollisionTuple>(admin, id1);
    auto t2 = GetById<CollisionTuple>(admin, id2);

    if (t1.has_value() && t2.has_value()) {
        get<CHealth>(t1.value().get()).life -= get<CCollisionDamage>(t2.value().get()).damage;
        get<CHealth>(t2.value().get()).life -= get<CCollisionDamage>(t1.value().get()).damage;
    }
}

bool ecs::CollisionSystem::isCollision(const std::pair<ReceiveProtocol::Key, std::string> &pair)
{
    return pair.first == ReceiveProtocol::COLLISION;
}
