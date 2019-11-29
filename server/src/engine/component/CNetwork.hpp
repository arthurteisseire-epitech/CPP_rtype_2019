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

namespace ecs
{
    struct CNetwork {
        explicit CNetwork(int port) :
            ioContext(),
            acceptor(ioContext, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
        {
        }

        boost::asio::io_context ioContext;
        boost::asio::ip::tcp::acceptor acceptor;
    };
}

#endif
