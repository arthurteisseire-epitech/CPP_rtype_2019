/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Packet.hpp
*/

#ifndef RTYPE_PACKET_HPP
#define RTYPE_PACKET_HPP

#include <array>

namespace ecs
{
    struct Packet {
        uint32_t magic = 9360624;
        std::array<uint8_t, 256> data{};
        uint32_t entityId{};
    };
}

#endif
