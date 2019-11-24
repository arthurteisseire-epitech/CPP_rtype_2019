/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ConnectionComponent.hpp
*/

#ifndef RTYPE_CONNECTIONCOMPONENT_HPP
#define RTYPE_CONNECTIONCOMPONENT_HPP

#include <boost/asio/ip/tcp.hpp>
#include <array>
#include <queue>

namespace ecs
{
    struct ConnectionComponent {
        explicit ConnectionComponent(boost::asio::io_context &ioContext) :
            socket(ioContext)
        {
        }

        boost::asio::ip::tcp::socket socket;
        std::queue<std::array<char, 1024>> readBuffers;
        std::array<char, 1024> tmpBuffer{};
        std::array<char, 1024> writeBuffer{};
    };
}

#endif
