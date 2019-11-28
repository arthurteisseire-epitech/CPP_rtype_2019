/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** NetworkUtil.hpp
*/

#ifndef RTYPE_NETWORKUTIL_HPP
#define RTYPE_NETWORKUTIL_HPP

#include <string>
#include "ConnectionComponent.hpp"
#include "EntityAdmin.hpp"

namespace ecs
{
    class NetworkUtil {
    public:
        static void send(const std::shared_ptr<EntityAdmin> &admin, ObjectPool<ConnectionComponent>::index connIdx,
                         const std::array<char, 1024> &buffer);

    private:
        static void handleSend(std::shared_ptr<EntityAdmin> &admin, ObjectPool<ConnectionComponent>::index connIdx,
                               const std::array<char, 1024> *buffer,
                               const boost::system::error_code &err);
    };
}

#endif
