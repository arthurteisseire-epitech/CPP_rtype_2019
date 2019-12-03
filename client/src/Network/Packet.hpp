/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Vleb
*/

#ifndef RTYPE_PACKET_HPP
#define RTYPE_PACKET_HPP

#include <cstdint>
#include <SFML/Network.hpp>
#include "INetwork.hpp"

namespace Client {
    struct RawPacket {
        uint32_t magic;
        uint8_t payload[256];
    };

    class Packet {
    public:
        Packet(const void *addr = nullptr, const uint32_t &size = 0);
        ~Packet();
        RawPacket *getRaw() const;
        uint8_t *getPayload() const;
        void setPayload(const void *addr, const uint32_t &size);
    private:
        RawPacket *_packet;
    };
}

#endif
