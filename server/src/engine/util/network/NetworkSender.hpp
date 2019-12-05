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
                         const std::array<char, 1024> &buffer);

    private:
        NetworkSender(const std::shared_ptr<EntityAdmin> &admin, ObjectPool<CConnection>::index connIdx,
                      const std::array<char, 1024> &buffer);

        static void handleSend(NetworkSender *sender);
        std::array<char, 1024> writeBuffer;
    };
}

#endif
