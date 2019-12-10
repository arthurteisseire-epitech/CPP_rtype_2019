/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** NetworkSender.hpp
*/

#ifndef RTYPE_NETWORKSENDER_HPP
#define RTYPE_NETWORKSENDER_HPP

#include <boost/asio.hpp>
#include "EntityAdmin.hpp"

namespace ecs
{
    class NetworkSender {
    public:
        static void send(const std::shared_ptr<EntityAdmin> &admin, ObjectPool<CConnection>::index connIdx,
                         const Packet &buffer);

    private:
        NetworkSender(const std::shared_ptr<EntityAdmin> &admin, ObjectPool<CConnection>::index connIdx,
                      const Packet &buffer);

        static void handleSend(NetworkSender *sender);
        Packet writeBuffer;
    };
}

#endif
