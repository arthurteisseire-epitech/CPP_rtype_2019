/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** EntityFactory.hpp
*/

#ifndef RTYPE_ENTITYFACTORY_HPP
#define RTYPE_ENTITYFACTORY_HPP

#include "CConnection.hpp"
#include "EntityAdmin.hpp"

namespace ecs
{
    class EntityFactory {
    public:
        static void createPlayer(std::shared_ptr<EntityAdmin> &admin, ObjectPool<CConnection>::index connIdx);
        static void createBullet(std::shared_ptr<EntityAdmin> &admin, ObjectPool<CConnection>::index connIdx,
                                 ObjectPool<CTransform>::index transformIdx);
    private:
        static int id;
    };
}

#endif
