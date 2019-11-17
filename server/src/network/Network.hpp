/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Network.hpp
*/

#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <boost/asio.hpp>
#include "Connection.hpp"

namespace net
{
    template<typename Func>
    class Network {
    public:
        Network(int portNumber, std::shared_ptr<Func> callback) :
            callback(callback)
        {
            acceptor = std::unique_ptr<boost::asio::ip::tcp::acceptor>(
                new boost::asio::ip::tcp::acceptor(
                    ioContext,
                    boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), portNumber)
                )
            );
            startAccept();
            ioContext.run();
        }

        ~Network()
        {
            ioContext.stop();
        }

    private:
        void startAccept()
        {
            auto connection = Connection<Func>::create(ioContext, callback);

            acceptor->async_accept(
                connection->socket(),
                boost::bind(&Network::handleAccept, this, connection, boost::asio::placeholders::error)
            );
        }

        void handleAccept(const boost::shared_ptr<Connection<Func>> &connection, const boost::system::error_code &err)
        {
            if (!err)
                connection->start();
            startAccept();
        }

        std::unique_ptr<boost::asio::ip::tcp::acceptor> acceptor;
        boost::asio::io_context ioContext;
        std::shared_ptr<Func> callback;
    };
}

#endif
