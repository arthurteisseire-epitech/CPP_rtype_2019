/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Connection.hpp
*/

#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#define BUFFER_SIZE 1024

#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

namespace net
{
    template<typename Func>
    class Connection : public boost::enable_shared_from_this<Connection<Func>> {
    public:

        template<typename Fun>
        static boost::shared_ptr<Connection> create(boost::asio::io_context &ioContext, std::shared_ptr<Fun> callback)
        {
            return boost::shared_ptr<Connection>(new Connection(ioContext, callback));
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
                    close();
                else
                    start();
            } else {
                close();
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
                close();
        }

        boost::asio::ip::tcp::socket &socket()
        {
            return sock;
        }

    private:
        Connection(boost::asio::io_context &ioContext, std::shared_ptr<Func> callback) :
            callback(std::move(callback)),
            sock(ioContext),
            readBuffer(),
            writeBuffer()
        {
        }

        void close()
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
}

#endif
