/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CNetwork.hpp
*/

#ifndef RTYPE_CNETWORK_HPP
#define RTYPE_CNETWORK_HPP

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <queue>

namespace ecs
{
    struct CNetwork {
        explicit CNetwork(int port) :
            ioContext(),
            socket(ioContext, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port))
        {
        }

        boost::asio::io_context ioContext;
        boost::asio::ip::udp::socket socket;
        std::queue<std::pair<boost::asio::ip::udp::endpoint, std::array<char, 1024>>> readBuffers;
    };
}

#endif
