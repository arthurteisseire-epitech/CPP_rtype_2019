/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Vleb
*/

#ifndef RTYPE_PACKET_HPP
#define RTYPE_PACKET_HPP

#define MAGIC_NB 9360624
#define DEFAULT_ID 0

#include <cstdint>
#include <SFML/Network.hpp>
#include <string>

namespace Client {
    struct RawPacket {
        uint32_t magic;
        std::array<uint8_t, 256> payload;
        uint32_t id;
    };

    class Packet {
    public:
        Packet(const uint32_t &id = DEFAULT_ID);
        Packet(const std::string &payload, const uint32_t &id = DEFAULT_ID);
        Packet(const RawPacket &rawPacket);
        ~Packet();
        RawPacket *getRaw() const;
        std::string getPayload() const;
        uint32_t getId() const;
        void setPayload(const std::string &payload);
    private:
        RawPacket *_packet;
    };
}

#endif
