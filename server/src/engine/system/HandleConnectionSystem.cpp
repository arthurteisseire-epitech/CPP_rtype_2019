/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** HandleConnectionSystem.cpp
*/

#include "NetworkSender.hpp"
#include "HandleConnectionSystem.hpp"

ecs::HandleConnectionSystem::HandleConnectionSystem(std::shared_ptr<EntityAdmin> admin) :
    ASystem(std::move(admin))
{
}

void ecs::HandleConnectionSystem::update(float dt)
{
    ForEachMatching<HandleConnectionTuple>(admin, [this](HandleConnectionTuple &t) {
        auto &c = get<CCommand>(t).commands;
        if (std::find(c.begin(), c.end(), CCommand::CONNECT) != c.end()) {
            ForEachMatching<HandleConnectionTuple>(admin, [this, &t](HandleConnectionTuple &t2) {
                if (get<CId>(t).id != get<CId>(t2).id)
                    NetworkSender::send(admin,
                                        GetIndex<CConnection>(t2),
                                        Packet(get<CId>(t2).id, "mate connected"));
                else
                    NetworkSender::send(admin,
                                        GetIndex<CConnection>(t2),
                                        Packet(get<CId>(t2).id, "player connected"));
            });
        }
    });
}
