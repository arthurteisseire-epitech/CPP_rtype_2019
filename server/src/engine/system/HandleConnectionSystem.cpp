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
    if (ReceiveProtocol::any(ReceiveProtocol::CONNECT, c)) {
        ForEachMatching<HandleConnectionTuple>(admin, [this, &t](HandleConnectionTuple &t2) {
            if (get<CId>(t).id != get<CId>(t2).id)
                NetworkSender::send(admin,
                                    GetIndex<CConnection>(t2),
                                    Packet(get<CId>(t2).id, SendProtocol::get(SendProtocol::NEW_CONNECTION)));
            else
                NetworkSender::send(admin,
                                    GetIndex<CConnection>(t2),
                                    Packet(get<CId>(t2).id, SendProtocol::get(SendProtocol::CONNECTED)));
        });
    }
}
