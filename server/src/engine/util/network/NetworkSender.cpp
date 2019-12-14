/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** NetworkSender.cpp
*/

#include <boost/bind.hpp>
#include <utility>
#include "NetworkSender.hpp"
#include "Util.hpp"

void ecs::NetworkSender::send(const std::shared_ptr<EntityAdmin> &admin, ecs::ObjectPool<ecs::CConnection>::index connIdx,
                              const Packet &buffer)
{
    send(admin, GetPool<CConnection>(admin).at(connIdx), buffer);
}

void ecs::NetworkSender::send(const std::shared_ptr<EntityAdmin> &admin, const CConnection &conn,
                              const ecs::Packet &buffer)
{
    send(admin, conn.endpoint, buffer);
}

void ecs::NetworkSender::send(const std::shared_ptr<EntityAdmin> &admin, const boost::asio::ip::udp::endpoint &endpoint,
                              const ecs::Packet &buffer)
{
    new NetworkSender(admin, endpoint, buffer);
}

ecs::NetworkSender::NetworkSender(const std::shared_ptr<EntityAdmin> &admin, const boost::asio::ip::udp::endpoint& endpoint,
                                  const Packet &buffer) :
    writeBuffer(buffer)
{
    admin->network.socket.async_send_to(
        boost::asio::buffer(&writeBuffer, sizeof(writeBuffer)),
        endpoint,
        std::bind(&ecs::NetworkSender::handleSend, this)
    );
}

void ecs::NetworkSender::handleSend(NetworkSender *sender)
{
    delete sender;
}
