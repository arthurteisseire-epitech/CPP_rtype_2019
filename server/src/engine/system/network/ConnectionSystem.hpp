/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ConnectionSystem.hpp
*/

#ifndef RTYPE_CONNECTIONSYSTEM_HPP
#define RTYPE_CONNECTIONSYSTEM_HPP

#include <optional>
#include "ASystem.hpp"
#include "EntityAdmin.hpp"
#include "CConnection.hpp"

namespace ecs
{
    class ConnectionSystem : public ASystem {
    public:
        explicit ConnectionSystem(std::shared_ptr<EntityAdmin> admin);

        void update(float deltaTime) override;
        void startAccept();
        void handleAccept(const boost::system::error_code &err);
        void startRead(ObjectPool<CConnection>::index connIdx);
        void handleRead(ObjectPool<CConnection>::index connIdx, const boost::system::error_code &err);
        void close(ObjectPool<CConnection>::index connIdx);

    private:
        std::optional<CConnection> connection;
    };
}

#endif
