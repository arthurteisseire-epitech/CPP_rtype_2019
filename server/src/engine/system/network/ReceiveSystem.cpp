/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ReceiveSystem.cpp
*/

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include "ReceiveSystem.hpp"

ecs::ReceiveSystem::ReceiveSystem(std::shared_ptr<EntityAdmin> admin) :
    ASystem(std::move(admin)),
    readBuffer(),
    endpoint()
{
}

void ecs::ReceiveSystem::update(float)
{
    startReceive();
    admin->network.ioContext.run();
}

void ecs::ReceiveSystem::startReceive()
{
    admin->network.socket.async_receive_from(
        boost::asio::buffer(&readBuffer, sizeof(readBuffer)),
        endpoint,
        boost::bind(
            &ecs::ReceiveSystem::handleReceive,
            this,
            boost::asio::placeholders::error
        )
    );
}

void ecs::ReceiveSystem::handleReceive(const boost::system::error_code &err)
{
    if (!err) {
        admin->network.readBuffers.emplace(endpoint, readBuffer);
        startReceive();
    }
}
