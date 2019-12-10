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
        explicit Packet(uint32_t entityId = 0) :
            entityId(entityId)
        {
        }

        Packet(uint32_t entityId, const std::string &s) :
            entityId(entityId)
        {
            std::copy(s.begin(), s.end(), data.begin());
        }

        void clear()
        {
            data.fill(0);
            entityId = 0;
        }

        [[nodiscard]] uint32_t getEntityId() const
        {
            return entityId;
        }

//        uint32_t magic = 9360624;
        std::array<uint8_t, 256> data{};
    private:
        uint32_t entityId{};
    };
}

#endif
