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
#include "ConnectionComponent.hpp"

namespace ecs
{
    class ConnectionSystem : public ASystem {
    public:
        explicit ConnectionSystem(std::shared_ptr<EntityAdmin> admin);

        void update(float deltaTime) override;
        void startAccept();
        void handleAccept(const boost::system::error_code &err);
        void startRead(size_t connIdx);
        void handleRead(size_t connIdx, const boost::system::error_code &err);
        static void write(ecs::ConnectionComponent &conn);
        static void handleWrite(const boost::system::error_code &err);
        void close(size_t connIdx);

    private:
        std::optional<ConnectionComponent> connection;
    };
}

#endif
