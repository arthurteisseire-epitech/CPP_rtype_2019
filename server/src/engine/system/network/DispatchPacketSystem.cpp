/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** DispatchPacketSystem.cpp
*/

#include <utility>
#include "DispatchPacketSystem.hpp"
#include "EntityFactory.hpp"
#include "NetworkSender.hpp"
#include "SendProtocol.hpp"

ecs::DispatchPacketSystem::DispatchPacketSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(std::move(admin))
{
}

void ecs::DispatchPacketSystem::update(float)
{
    auto &buffers = admin->network.readBuffers;

    while (true) {
        auto p = buffers.pop();

        auto optConn = FindOneMatching<CConnection>(admin, [&p] (CConnection &conn) {
            return conn.endpoint == p.first;
        });

        if (!optConn.has_value()) {
            auto connIdx = GetPool<CConnection>(admin).create(p.first);
            NetworkSender::send(admin, connIdx, Packet(0, SendProtocol::get(SendProtocol::CONNECTED)));
            GetPool<CConnection>(admin).at(connIdx).readBuffers.push(p.second);
        } else {
            optConn.value().get().readBuffers.push(p.second);
        }
    }
}
