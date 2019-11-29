/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CConnection.hpp
*/

#ifndef RTYPE_CCONNECTION_HPP
#define RTYPE_CCONNECTION_HPP

#include <boost/asio/ip/tcp.hpp>
#include <array>
#include <queue>
#include <deque>

namespace ecs
{
    struct CConnection {
        explicit CConnection(boost::asio::io_context &ioContext) :
            socket(ioContext)
        {
        }

        boost::asio::ip::tcp::socket socket;
        std::queue<std::array<char, 1024>> readBuffers;
        std::array<char, 1024> tmpReadBuffer{};
        std::deque<std::array<char, 1024>> writeBuffer{};
    };
}

#endif
