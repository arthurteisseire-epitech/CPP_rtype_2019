/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Vleb
*/

#ifndef RTYPE_PACKET_HPP
#define RTYPE_PACKET_HPP

#define DEFAULT_ID 0

#include <cstdint>
#include <SFML/Network.hpp>
#include <string>

namespace Client {
    struct RawPacket {
        uint32_t magic;
        uint8_t payload[256];
        uint32_t id;
    };

    class Packet {
    public:
        Packet(const uint32_t &id = DEFAULT_ID);
        Packet(const std::string &payload, const uint32_t &id = DEFAULT_ID);
        Packet(const RawPacket &rawPacket);
        ~Packet();
        RawPacket *getRaw() const;
        uint8_t *getPayload() const;
        uint32_t getId() const;
        void setPayload(const void *addr, const uint32_t &size);
        void setPayload(const std::string &payload);
    private:
        RawPacket *_packet;
    };
}

#endif
