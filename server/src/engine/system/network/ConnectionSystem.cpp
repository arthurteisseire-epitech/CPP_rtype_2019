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

    std::cout << "new connection !" << std::endl;
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
    const std::string exit = "exit";
    const std::string left = "left";
    const std::string right = "right";
    const std::string up = "up";
    const std::string down = "down";

    if (!err) {
        std::cout << "readBuffer: '" << conn->readBuffer.data() << "'" << std::endl;
        conn->writeBuffer.fill(0);
        if (std::equal(exit.begin(), exit.end(), conn->readBuffer.begin()))
            close(conn);
        else if (std::equal(left.begin(), left.end(), conn->readBuffer.begin()))
            fill_buffer(conn->writeBuffer, "go left\n");
        else if (std::equal(right.begin(), right.end(), conn->readBuffer.begin()))
            fill_buffer(conn->writeBuffer, "go right\n");
        else if (std::equal(up.begin(), up.end(), conn->readBuffer.begin()))
            fill_buffer(conn->writeBuffer, "go up\n");
        else if (std::equal(down.begin(), down.end(), conn->readBuffer.begin()))
            fill_buffer(conn->writeBuffer, "go down\n");
        else
            fill_buffer(conn->writeBuffer, "command not found\n");
        write(conn);
        std::cout << conn->writeBuffer.data() << std::endl;
        startRead(conn);
    }
}

void ecs::ConnectionSystem::write(ecs::ConnectionComponent *conn)
{
    conn->socket.async_write_some(
        boost::asio::buffer(conn->writeBuffer),
        boost::bind(
            &ecs::ConnectionSystem::handleWrite,
            boost::asio::placeholders::error
        )
    );
}

void ecs::ConnectionSystem::handleWrite(const boost::system::error_code &err)
{
    if (err)
        std::cout << "handle write: " << err << std::endl;
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

void ecs::ConnectionSystem::fill_buffer(std::array<char, 1024> &buffer, const std::string &s)
{
    std::copy(s.begin(), s.end(), buffer.begin());
}
