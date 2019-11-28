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
        static void createPlayer(std::shared_ptr<EntityAdmin> &admin, ObjectPool<ConnectionComponent>::index connIdx);
        static void createBullet(std::shared_ptr<EntityAdmin> &admin, ObjectPool<ConnectionComponent>::index connIdx,
                                 ObjectPool<TransformComponent>::index transformIdx);
    private:
        static int id;
    };
}

#endif