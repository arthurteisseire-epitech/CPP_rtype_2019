/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** NetworkUtil.cpp
*/

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include "NetworkUtil.hpp"

void ecs::NetworkUtil::send(ecs::ConnectionComponent *connection, const std::array<char, 1024> &buffer)
{
    std::copy(buffer.begin(), buffer.end(), connection->writeBuffer.begin());
    connection->socket.async_write_some(
        boost::asio::buffer(connection->writeBuffer),
        boost::bind(
            &ecs::NetworkUtil::handleSend,
            boost::asio::placeholders::error
        )
    );
}

void ecs::NetworkUtil::handleSend(const boost::system::error_code &err)
{
}
