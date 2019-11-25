/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** NetworkUtil.cpp
*/

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "NetworkUtil.hpp"

void ecs::NetworkUtil::send(ecs::ConnectionComponent *connection, const std::array<char, 1024> &buffer)
{
    auto &b = connection->writeBuffer.emplace_back(buffer);

    connection->socket.async_write_some(
        boost::asio::buffer(b),
        boost::bind(
            &ecs::NetworkUtil::handleSend,
            connection,
            &b,
            boost::asio::placeholders::error
        )
    );
}

void ecs::NetworkUtil::handleSend(ConnectionComponent *conn, const std::array<char, 1024> *buffer,
                                  const boost::system::error_code &err)
{
    auto &q = conn->writeBuffer;

    q.erase(std::remove_if(q.begin(), q.end(), [buffer] (const std::array<char, 1024> &b) {
        return &b == buffer;
    }), q.end());
}
