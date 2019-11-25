/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ConnectionSystem.cpp
*/

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include "EntityFactory.hpp"
#include "NetworkComponent.hpp"
#include "ConnectionSystem.hpp"
#include "ConnectionComponent.hpp"
#include "Util.hpp"

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

    if (err) {
        std::cout << err << std::endl;
    } else {
        std::cout << "new connection !" << std::endl;
        auto conn = &connPool.move(std::move(connection.value()));
        startRead(conn);
        EntityFactory::createPlayer(admin, conn);
    }
    startAccept();
}

void ecs::ConnectionSystem::startRead(ecs::ConnectionComponent *conn)
{
    conn->tmpReadBuffer.fill(0);
    conn->socket.async_read_some(
        boost::asio::buffer(conn->tmpReadBuffer),
        boost::bind(
            &ecs::ConnectionSystem::handleRead,
            this,
            conn,
            boost::asio::placeholders::error
        )
    );
}

void ecs::ConnectionSystem::handleRead(ConnectionComponent *conn, const boost::system::error_code &err)
{
    if (!err) {
        conn->readBuffers.push(conn->tmpReadBuffer);
        startRead(conn);
    }
}

//void ecs::ConnectionSystem::write(ecs::ConnectionComponent *conn)
//{
//    conn->socket.async_write_some(
//        boost::asio::buffer(conn->writeBuffer),
//        boost::bind(
//            &ecs::ConnectionSystem::handleWrite,
//            boost::asio::placeholders::error
//        )
//    );
//}
//
//void ecs::ConnectionSystem::handleWrite(const boost::system::error_code &err)
//{
//    if (err)
//        std::cout << "handle write: " << err << std::endl;
//}

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
