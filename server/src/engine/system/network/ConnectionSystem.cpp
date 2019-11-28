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
        std::size_t connIdx = connPool.move(std::move(connection.value()));
        startRead(connIdx);
        EntityFactory::createPlayer(admin, connIdx);
    }
    startAccept();
}

void ecs::ConnectionSystem::startRead(size_t connIdx)
{
    auto &conn = GetPool<ConnectionComponent>(admin).at(connIdx);

    conn.tmpReadBuffer.fill(0);
    conn.socket.async_read_some(
        boost::asio::buffer(conn.tmpReadBuffer),
        boost::bind(
            &ecs::ConnectionSystem::handleRead,
            this,
            connIdx,
            boost::asio::placeholders::error
        )
    );
}

void ecs::ConnectionSystem::handleRead(size_t connIdx, const boost::system::error_code &err)
{
    if (!err) {
        auto &conn = GetPool<ConnectionComponent>(admin).at(connIdx);
        conn.readBuffers.push(conn.tmpReadBuffer);
        startRead(connIdx);
    }
}

void ecs::ConnectionSystem::close(size_t connIdx)
{
    auto &conn = GetPool<ConnectionComponent>(admin).at(connIdx);
    boost::system::error_code ec;

    conn.socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);
    if (ec)
        std::cerr << "error in shutdown: " << ec << std::endl;
    conn.socket.close(ec);
    if (ec)
        std::cerr << "error in close: " << ec << std::endl;
    GetPool<ecs::ConnectionComponent>(admin).destroy(connIdx);
}
