/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ConnectionSystem.cpp
*/

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include "NetworkComponent.hpp"
#include "ConnectionSystem.hpp"
#include "ConnectionComponent.hpp"
#include "GetPool.hpp"

ecs::ConnectionSystem::ConnectionSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(std::move(admin))
{
}

void ecs::ConnectionSystem::update(float deltaTime)
{
    startAccept();
    admin->network.ioContext.run();
}

void ecs::ConnectionSystem::startAccept()
{
    connection = ConnectionComponent(admin->network.ioContext);

    admin->network.acceptor.async_accept(
        connection.value().socket,
        boost::bind(&ecs::ConnectionSystem::handleAccept, this, boost::asio::placeholders::error)
    );
}

void ecs::ConnectionSystem::handleAccept(const boost::system::error_code &err)
{
    auto &connPool = GetPool<ecs::ConnectionComponent>(admin);

    if (err)
        std::cout << err << std::endl;
    else
        startRead(&connPool.move(std::move(connection.value())));
    startAccept();
}

void ecs::ConnectionSystem::startRead(ecs::ConnectionComponent *conn)
{
    conn->readBuffer.fill(0);
    conn->socket.async_read_some(
        boost::asio::buffer(conn->readBuffer),
        boost::bind(
            &ecs::ConnectionSystem::handleRead,
            this,
            conn,
            boost::asio::placeholders::error
        )
    );
}

void ecs::ConnectionSystem::handleRead(ecs::ConnectionComponent *conn, const boost::system::error_code &err)
{
    if (!err) {
        write(conn, conn->readBuffer);
        startRead(conn);
    }
}

void ecs::ConnectionSystem::write(ecs::ConnectionComponent *conn, const std::array<char, 1024> &response)
{
    const std::string exit = "exit";

    conn->socket.async_write_some(
        boost::asio::buffer(response),
        boost::bind(
            &ecs::ConnectionSystem::handleWrite,
            boost::asio::placeholders::error
        )
    );
    if (std::equal(exit.begin(), exit.end(), response.begin()))
        close(conn);
}

void ecs::ConnectionSystem::handleWrite(const boost::system::error_code &)
{
}

void ecs::ConnectionSystem::close(ConnectionComponent *conn)
{
    boost::system::error_code ec;

    conn->socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);
    if (ec)
        std::cerr << "error in shutdown: " << ec << std::endl;
    conn->socket.close(ec);
    if (ec)
        std::cerr << "error in close: " << ec << std::endl;
    GetPool<ecs::ConnectionComponent>(admin).destroy(conn);
}
