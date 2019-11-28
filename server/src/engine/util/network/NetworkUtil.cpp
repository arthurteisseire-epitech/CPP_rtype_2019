/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** NetworkUtil.cpp
*/

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "Util.hpp"
#include "NetworkUtil.hpp"

void ecs::NetworkUtil::send(const std::shared_ptr<EntityAdmin> &admin, ObjectPool<ConnectionComponent>::index connIdx,
                            const std::array<char, 1024> &buffer)
{
    auto &conn = GetPool<ConnectionComponent>(admin).at(connIdx);
    auto &b = conn.writeBuffer.emplace_back(buffer);

    conn.socket.async_write_some(
        boost::asio::buffer(b),
        boost::bind(
            &ecs::NetworkUtil::handleSend,
            admin,
            connIdx,
            &b,
            boost::asio::placeholders::error
        )
    );
}

void ecs::NetworkUtil::handleSend(std::shared_ptr<EntityAdmin> &admin, ObjectPool<ConnectionComponent>::index connIdx,
                                  const std::array<char, 1024> *buffer,
                                  const boost::system::error_code &err)
{
    //    auto &conn = GetPool<ConnectionComponent>(admin).at(connIdx);
    //    auto &q = conn.writeBuffer;
    //
    //    q.erase(std::remove_if(q.begin(), q.end(), [buffer](const std::array<char, 1024> &b) {
    //        return &b == buffer;
    //    }), q.end());
}
