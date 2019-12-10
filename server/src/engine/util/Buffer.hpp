/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Buffer.hpp
*/

#ifndef RTYPE_BUFFER_HPP
#define RTYPE_BUFFER_HPP

#include <array>

namespace ecs
{
    struct Buffer {
        uint32_t magic = 9360624;
        std::array<uint8_t, 256> data{};
        uint32_t id{};
    };
}

#endif
