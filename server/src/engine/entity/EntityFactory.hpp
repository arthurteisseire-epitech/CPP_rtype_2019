/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** EntityFactory.hpp
*/

#ifndef RTYPE_ENTITYFACTORY_HPP
#define RTYPE_ENTITYFACTORY_HPP

#include "ConnectionComponent.hpp"
#include "EntityAdmin.hpp"

namespace ecs
{
    class EntityFactory {
    public:
        static void createPlayer(std::shared_ptr<EntityAdmin> &admin, ConnectionComponent *connection);
        static void createBullet(std::shared_ptr<EntityAdmin> &admin, ConnectionComponent *connection,
                                 TransformComponent *transform);
    private:
        static int id;
    };
}

#endif
