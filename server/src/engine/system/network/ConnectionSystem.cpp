/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ConnectionSystem.cpp
*/

#include <utility>
#include "ConnectionSystem.hpp"
#include "EntityFactory.hpp"

ecs::ConnectionSystem::ConnectionSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(std::move(admin))
{
}

void ecs::ConnectionSystem::update(float)
{
    auto &buffers = admin->network.readBuffers;

    while (!buffers.empty()) {
        auto &p = buffers.front();

        auto &connPool = GetPool<CConnection>(admin);
        auto it = std::find_if(connPool.begin(), connPool.end(), [&p] (auto &pair) {
            return pair.second.endpoint == p.first;
        });

        if (it == connPool.end()) {
            auto connIdx = connPool.create(p.first);
            EntityFactory::createPlayer(admin, connIdx);
            GetPool<CConnection>(admin).at(connIdx).readBuffers.push(p.second);
        } else {
            it->second.readBuffers.push(p.second);
        }
        buffers.pop();
    }
}
