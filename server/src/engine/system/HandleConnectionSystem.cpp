/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** HandleConnectionSystem.cpp
*/

#include <any>
#include "HandleConnectionSystem.hpp"
#include "NetworkSender.hpp"
#include "SendProtocol.hpp"
#include "ReceiveProtocol.hpp"

ecs::HandleConnectionSystem::HandleConnectionSystem(std::shared_ptr<EntityAdmin> admin) :
    ASystem(std::move(admin))
{
}

void ecs::HandleConnectionSystem::update(float dt)
{
    ForEachMatching<HandleConnectionTuple>(admin, std::bind(&HandleConnectionSystem::updateTuple, this, std::placeholders::_1));
}

void ecs::HandleConnectionSystem::updateTuple(ecs::HandleConnectionTuple &t)
{
    auto &c = get<CCommand>(t).commands;
    if (std::any_of(c.begin(), c.end(), isConnect)) {
        ForEachMatching<HandleConnectionTuple>(admin, [this, &t](HandleConnectionTuple &t2) {
            if (get<CId>(t).id != get<CId>(t2).id)
                NetworkSender::send(admin,
                                    GetIndex<CConnection>(t2),
                                    Packet(get<CId>(t2).id, SendProtocol::get(SendProtocol::MATE_CONNECTED)));
            else
                NetworkSender::send(admin,
                                    GetIndex<CConnection>(t2),
                                    Packet(get<CId>(t2).id, SendProtocol::get(SendProtocol::CONNECTED)));
        });
    }
}

bool ecs::HandleConnectionSystem::isConnect(const std::pair<ReceiveProtocol::Key, std::string> &pair)
{
    return pair.first == ReceiveProtocol::CONNECT;
}
