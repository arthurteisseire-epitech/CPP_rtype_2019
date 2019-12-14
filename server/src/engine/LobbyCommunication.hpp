/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** LobbyCommunication.hpp
*/

#ifndef RTYPE_LOBBYCOMMUNICATION_HPP
#define RTYPE_LOBBYCOMMUNICATION_HPP

#include "EntityAdmin.hpp"
#include "SystemUtil.hpp"

namespace ecs
{
    class LobbyCommunication {
    public:
        static void waitForStartGame(std::shared_ptr<EntityAdmin> &admin);
        static void notifyPlayers(std::shared_ptr<EntityAdmin> &admin);
        static void startGame(std::shared_ptr<EntityAdmin> &admin, std::vector<std::unique_ptr<ASystem>> &systems);

    private:
        static void notifyAllMates(std::shared_ptr<EntityAdmin> &admin, Packet &packet, const boost::asio::ip::udp::endpoint &endpoint);
    };
}

#endif
