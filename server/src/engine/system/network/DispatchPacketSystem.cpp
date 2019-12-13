/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** DispatchPacketSystem.cpp
*/

#include <utility>
#include "DispatchPacketSystem.hpp"
#include "EntityFactory.hpp"

ecs::DispatchPacketSystem::DispatchPacketSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(std::move(admin))
{
}

void ecs::DispatchPacketSystem::update(float)
{
    auto &buffers = admin->network.readBuffers;

    while (!buffers.empty()) {
        auto &p = buffers.front();

        auto optConn = FindOneMatching<CConnection>(admin, [&p] (CConnection &conn) {
            return conn.endpoint == p.first;
        });

        if (!optConn.has_value()) {
            auto connIdx = GetPool<CConnection>(admin).create(p.first);
            EntityFactory::createPlayer(admin, connIdx);
            GetPool<CConnection>(admin).at(connIdx).readBuffers.push(p.second);
        } else {
            optConn.value().get().readBuffers.push(p.second);
        }
        buffers.pop();
    }
}
