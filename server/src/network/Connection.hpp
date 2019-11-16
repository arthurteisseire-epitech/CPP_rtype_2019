/*
** EPITECH PROJECT, 2019
** babel
** File description:
** Connection.hpp
*/

#ifndef BABEL_CONNECTION_HPP
#define BABEL_CONNECTION_HPP

#define BUFFER_SIZE 1024

#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

template<typename Func>
class Connection : public boost::enable_shared_from_this<Connection<Func>> {
public:

    template<typename Fun>
    static boost::shared_ptr<Connection> create(boost::asio::executor &executor, std::shared_ptr<Fun> callback)
    {
        return boost::shared_ptr<Connection>(new Connection(executor, callback));
    }

    void start()
    {
        readBuffer.fill(0);
        writeBuffer.fill(0);
        sock.async_read_some(
            boost::asio::buffer(readBuffer),
            boost::bind(
                &Connection::handleRead,
                this->shared_from_this(),
                boost::asio::placeholders::error
            )
        );
    }

    void handleRead(const boost::system::error_code &err)
    {
        if (!err) {
            auto wantToContinue = (*callback)(readBuffer, writeBuffer);
            send(writeBuffer);
            if (!wantToContinue)
                closeSocket();
            else
                start();
        } else {
            closeSocket();
        }
    }

    void send(const std::array<char, 1024> &response)
    {
        sock.async_write_some(
            boost::asio::buffer(response),
            boost::bind(
                &Connection::handleWrite,
                this->shared_from_this(),
                boost::asio::placeholders::error
            )
        );
    }

    void handleWrite(const boost::system::error_code &err)
    {
        if (err)
            closeSocket();
    }

    boost::asio::ip::tcp::socket &socket()
    {
        return sock;
    }

private:
    Connection(boost::asio::executor &executor, std::shared_ptr<Func> callback) :
        callback(std::move(callback)),
        sock(executor),
        readBuffer(),
        writeBuffer()
    {
    }

    void closeSocket()
    {
        boost::system::error_code ec;
        sock.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);
        if (ec)
            std::cerr << "error in shutdown: " << ec << std::endl;
        sock.close(ec);
        if (ec)
            std::cerr << "error in close: " << ec << std::endl;
    }

    std::shared_ptr<Func> callback;
    boost::asio::ip::tcp::socket sock;

    std::array<char, BUFFER_SIZE> readBuffer;
    std::array<char, BUFFER_SIZE> writeBuffer;
};

#endif
