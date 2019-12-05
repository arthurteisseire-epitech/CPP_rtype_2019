/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Sender.hpp
*/

#ifndef RTYPE_SENDER_HPP
#define RTYPE_SENDER_HPP

#include <boost/asio.hpp>
#include "EntityAdmin.hpp"

namespace ecs
{
    class Sender {
    public:
        Sender(const std::shared_ptr<EntityAdmin> &admin, ObjectPool<CConnection>::index connIdx,
               const std::array<char, 1024> &buffer);

        static void handleSend(Sender *sender);
    private:
        std::array<char, 1024> writeBuffer;
    };
}

#endif
