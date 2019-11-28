/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_INETWORK_HPP
#define RTYPE_INETWORK_HPP

#include <string>
#include <array>

namespace game
{
    class INetwork {
    public:
        virtual ~INetwork() = default;
        virtual bool connect(const std::string &IP, const unsigned &port) = 0;
        virtual void disconnect() = 0;
        virtual void send(const void *data, const size_t &, std::size_t &size) = 0;
        virtual bool receive(void *data, const std::size_t &size, std::size_t &received) = 0;
    };
}

#endif
