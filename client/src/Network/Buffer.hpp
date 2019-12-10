/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_BUFFER_HPP
#define RTYPE_BUFFER_HPP

#include <array>
#include <cstdint>

namespace game
{
    struct Buffer {
        Buffer() = default;

        Buffer(uint32_t entityId, const std::string &s) :
            magic(9360624),
            id(entityId)
        {
            data.fill(0);
            std::copy(s.begin(), s.end(), data.begin());
        }

        uint32_t magic;
        std::array<uint8_t, 256> data{};
        uint32_t id{};
    };
}

#endif
