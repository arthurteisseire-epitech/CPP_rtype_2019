/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SendSystem.cpp
*/

#include <boost/bind.hpp>
#include "SendProtocol.hpp"
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
    ForEachMatching<CConnection>(admin, [this, &t](CConnection &conn) {
        NetworkSender::send(admin, conn, Packet(get<CId>(t).id,
                                                SendProtocol::entitySetToString(get<CType>(t).name,
                                                                                get<CTransform>(t).vec.x,
                                                                                get<CTransform>(t).vec.y)));
    });
}
