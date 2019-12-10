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
    ForEachMatching<SendTuple>(admin, boost::bind(&ecs::SendSystem::updateTuple, this, _1));
}

void ecs::SendSystem::updateTuple(ecs::SendTuple &t)
{
    Packet packet;

    packet.entityId = get<CId>(t).id;
    auto s = get<CType>(t).name + ':' +
        std::to_string(get<CTransform>(t).vec.x) + ',' +
        std::to_string(get<CTransform>(t).vec.y) + '\n';
    std::copy(s.begin(), s.end(), packet.data.begin());
    NetworkSender::send(admin, GetIndex<CConnection>(t), packet);
}
