/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ConnectionSystem.cpp
*/

#include "NetworkComponent.hpp"
#include "Network.hpp"
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
    conn = ConnectionComponent(admin->network.ioContext);

    admin->network.acceptor.async_accept(
        conn.value().socket,
        boost::bind(&ecs::ConnectionSystem::handleAccept, this, boost::asio::placeholders::error)
    );
}

void ecs::ConnectionSystem::handleAccept(const boost::system::error_code &err)
{
    auto &connPool = GetPool<ecs::ConnectionComponent>(admin);

    if (err)
        std::cout << err << std::endl;
    else
        connPool.move(std::move(conn.value()));
    startAccept();
}
