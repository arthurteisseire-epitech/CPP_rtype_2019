/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ReceiveSystem.hpp
*/

#ifndef RTYPE_RECEIVESYSTEM_HPP
#define RTYPE_RECEIVESYSTEM_HPP

#include <optional>
#include "ASystem.hpp"
#include "EntityAdmin.hpp"
#include "CConnection.hpp"

namespace ecs
{
    class ReceiveSystem : public ASystem {
    public:
        explicit ReceiveSystem(std::shared_ptr<EntityAdmin> admin);

        void update(float deltaTime) override;
        void startReceive();
        void handleReceive(const boost::system::error_code &err);

    private:
        boost::asio::ip::udp::endpoint endpoint;
        Packet readBuffer;
    };
}

#endif
