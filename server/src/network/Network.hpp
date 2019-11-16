/*
** EPITECH PROJECT, 2019
** babel
** File description:
** Network.hpp
*/

#ifndef BABEL_BOOSTNETWORK_HPP
#define BABEL_BOOSTNETWORK_HPP

#include <boost/asio.hpp>
#include "Connection.hpp"

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
        auto executor = acceptor->get_executor();
        auto connection = Connection<Func>::create(executor, callback);

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

#endif
