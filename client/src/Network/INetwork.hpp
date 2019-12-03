/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios, modified by Vleb
*/

#ifndef RTYPE_INETWORK_HPP
#define RTYPE_INETWORK_HPP

#include <array>
#include <cstdint>
#include <string>

namespace Client {
    class INetwork {
    public:
        virtual ~INetwork() = default;
        virtual void send(const void *data, const std::size_t &size) = 0;
        virtual std::pair<std::string, uint16_t> receive(void *data, const std::size_t &size, std::size_t &received) = 0;
    };
}

#endif
