/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** HandleConnectionSystem.hpp
*/

#ifndef RTYPE_HANDLECONNECTIONSYSTEM_HPP
#define RTYPE_HANDLECONNECTIONSYSTEM_HPP

#include "ASystem.hpp"

namespace ecs
{
    class HandleConnectionSystem : public ASystem {
    public:
        explicit HandleConnectionSystem(std::shared_ptr<EntityAdmin> admin);
        void update(float dt) override;
        void updateTuple(HandleConnectionTuple &t1);

    private:
        void handleConnection(HandleConnectionTuple &t1, HandleConnectionTuple &t2);
        void handleDisconnection(HandleConnectionTuple &t1, HandleConnectionTuple &t2);

        static bool isConnect(const std::pair<ReceiveProtocol::Key, std::string> &pair);
        static bool isDisconnect(const std::pair<ReceiveProtocol::Key, std::string> &pair);
    };
}

#endif
