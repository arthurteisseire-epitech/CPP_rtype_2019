/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Sender.cpp
*/

#include <boost/bind.hpp>
#include "Sender.hpp"
#include "Util.hpp"

ecs::Sender::Sender(const std::shared_ptr<EntityAdmin> &admin, ecs::ObjectPool<ecs::CConnection>::index connIdx,
                    const std::array<char, 1024> &buffer) :
    writeBuffer(buffer)
{
    admin->network.socket.async_send_to(
        boost::asio::buffer(writeBuffer),
        GetPool<CConnection>(admin).at(connIdx).endpoint,
        boost::bind(&ecs::Sender::handleSend, this)
    );
}

void ecs::Sender::handleSend(Sender *sender)
{
    delete sender;
}
