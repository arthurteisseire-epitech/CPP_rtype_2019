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

namespace ecs
{
    class NetworkUtil {
    public:
        static void send(ConnectionComponent *connection, const std::array<char, 1024> &buffer);

    private:
        static void handleSend(const boost::system::error_code &err);
    };
}

#endif
