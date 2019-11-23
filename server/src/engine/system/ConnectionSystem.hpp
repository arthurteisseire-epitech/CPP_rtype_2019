/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ConnectionSystem.hpp
*/

#ifndef RTYPE_CONNECTIONSYSTEM_HPP
#define RTYPE_CONNECTIONSYSTEM_HPP

#include "ASystem.hpp"
#include "EntityAdmin.hpp"
#include "ConnectionComponent.hpp"

namespace ecs
{
    class ConnectionSystem : public ASystem {
    public:
        explicit ConnectionSystem(std::shared_ptr<EntityAdmin> admin);

        void update(float deltaTime);
        void startAccept();
        void handleAccept(ConnectionComponent *conn, const boost::system::error_code &err);
    };
}

#endif
