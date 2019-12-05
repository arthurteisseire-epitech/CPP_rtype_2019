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

void ecs::NetworkUtil::send(const std::shared_ptr<EntityAdmin> &admin, ObjectPool<CConnection>::index connIdx,
                            const std::array<char, 1024> &buffer)
{
    auto &conn = GetPool<CConnection>(admin).at(connIdx);
    auto &b = conn.writeBuffer.emplace_back(buffer);

    admin->network.socket.async_send_to(
        boost::asio::buffer(b),
        conn.endpoint,
        boost::bind(
            &ecs::NetworkUtil::handleSend,
            admin,
            connIdx,
            &b,
            boost::asio::placeholders::error
        )
    );
}

void ecs::NetworkUtil::handleSend(std::shared_ptr<EntityAdmin> &admin, ObjectPool<CConnection>::index connIdx,
                                  const std::array<char, 1024> *buffer,
                                  const boost::system::error_code &err)
{
    //    auto &conn = GetPool<CConnection>(admin).at(connIdx);
    //    auto &q = conn.writeBuffer;
    //
    //    q.erase(std::remove_if(q.begin(), q.end(), [buffer](const std::array<char, 1024> &b) {
    //        return &b == buffer;
    //    }), q.end());
}
