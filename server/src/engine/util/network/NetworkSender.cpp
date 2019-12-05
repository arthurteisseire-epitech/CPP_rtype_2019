/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** NetworkSender.cpp
*/

#include <boost/bind.hpp>
#include "NetworkSender.hpp"
#include "Util.hpp"

void ecs::NetworkSender::send(const std::shared_ptr<EntityAdmin> &admin, ecs::ObjectPool<ecs::CConnection>::index connIdx,
                              const std::array<char, 1024> &buffer)
{
    new NetworkSender(admin, connIdx, buffer);
}

ecs::NetworkSender::NetworkSender(const std::shared_ptr<EntityAdmin> &admin, ecs::ObjectPool<ecs::CConnection>::index connIdx,
                                  const std::array<char, 1024> &buffer) :
    writeBuffer(buffer)
{
    admin->network.socket.async_send_to(
        boost::asio::buffer(writeBuffer),
        GetPool<CConnection>(admin).at(connIdx).endpoint,
        boost::bind(&ecs::NetworkSender::handleSend, this)
    );
}

void ecs::NetworkSender::handleSend(NetworkSender *sender)
{
    delete sender;
}
