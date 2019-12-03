/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios, modified by Vleb
*/

#ifndef RTYPE_INETWORK_HPP
#define RTYPE_INETWORK_HPP

#include <cstdint>
#include "Packet.hpp"

namespace Client {
    class INetwork {
    public:
        virtual ~INetwork() = default;
        virtual void send(const void *data, const uint64_t &size) = 0;
        virtual void send(const Client::RawPacket *packet) = 0;
        virtual std::pair<std::string, uint16_t> receive(void *data, const uint64_t &size, uint64_t &received) = 0;
    };
}

#endif
