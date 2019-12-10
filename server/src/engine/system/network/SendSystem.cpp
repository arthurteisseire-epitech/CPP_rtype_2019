/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SendSystem.cpp
*/

#include <boost/bind.hpp>
#include "SendSystem.hpp"
#include "NetworkSender.hpp"
#include "Util.hpp"

ecs::SendSystem::SendSystem(std::shared_ptr<EntityAdmin> admin) :
    ASystem(std::move(admin))
{
}

void ecs::SendSystem::update(float deltaTime)
{
    ForEachMatching<SendTuple>(admin, std::bind(&ecs::SendSystem::updateTuple, this, std::placeholders::_1));
}

void ecs::SendSystem::updateTuple(ecs::SendTuple &t)
{
    ForEachMatching<CConnection>(admin, [this, &t] (CConnection &conn) {
        auto s = get<CType>(t).name + ':' +
            std::to_string(get<CTransform>(t).vec.x) + ',' +
            std::to_string(get<CTransform>(t).vec.y) + '\n';

        NetworkSender::send(admin, conn, Packet(get<CId>(t).id, s));
    });
}
