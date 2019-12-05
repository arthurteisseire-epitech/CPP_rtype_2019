/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CConnection.hpp
*/

#ifndef RTYPE_CCONNECTION_HPP
#define RTYPE_CCONNECTION_HPP

#include <boost/asio/ip/udp.hpp>
#include <array>
#include <queue>
#include <deque>
#include <utility>
#include "Buffer.hpp"

namespace ecs
{
    struct CConnection {
        explicit CConnection(boost::asio::ip::udp::endpoint endpoint) :
            endpoint(std::move(endpoint))
        {
        }

        const boost::asio::ip::udp::endpoint endpoint;
        std::queue<Buffer> readBuffers{};
    };
}

#endif
