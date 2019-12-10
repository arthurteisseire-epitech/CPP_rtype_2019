/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ReceiveSystem.cpp
*/

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
    readBuffer.clear();
    admin->network.socket.async_receive_from(
        boost::asio::buffer(&readBuffer, sizeof(readBuffer)),
        endpoint,
        std::bind(
            &ecs::ReceiveSystem::handleReceive,
            this,
            std::placeholders::_1
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
