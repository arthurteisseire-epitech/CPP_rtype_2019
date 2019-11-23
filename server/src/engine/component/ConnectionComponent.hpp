/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ConnectionComponent.hpp
*/

#ifndef RTYPE_CONNECTIONCOMPONENT_HPP
#define RTYPE_CONNECTIONCOMPONENT_HPP

#include <boost/asio/ip/tcp.hpp>

namespace ecs
{
    struct ConnectionComponent {
        explicit ConnectionComponent(boost::asio::io_context &ioContext) :
            socket(ioContext)
        {
        }

        boost::asio::ip::tcp::socket socket;
    };
}

#endif
