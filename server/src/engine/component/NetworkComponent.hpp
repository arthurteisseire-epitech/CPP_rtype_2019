/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** NetworkComponent.hpp
*/

#ifndef RTYPE_NETWORKCOMPONENT_HPP
#define RTYPE_NETWORKCOMPONENT_HPP

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>

namespace ecs
{
    struct NetworkComponent {
        explicit NetworkComponent(int port) :
            ioContext(),
            acceptor(ioContext, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
        {
        }

        boost::asio::io_context ioContext;
        boost::asio::ip::tcp::acceptor acceptor;
    };
}

#endif
