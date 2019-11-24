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

        void update(float deltaTime);
        void startAccept();
        void handleAccept(const boost::system::error_code &err);
        void startRead(ConnectionComponent *conn);
        void handleRead(ConnectionComponent *conn, const boost::system::error_code &err);
        void write(ecs::ConnectionComponent *conn);
        static void handleWrite(const boost::system::error_code &err);
        void close(ConnectionComponent *conn);

    private:
        static void fill_buffer(std::array<char, 1024> &buffer, const std::string &s);

        std::optional<ConnectionComponent> connection;
    };
}

#endif
