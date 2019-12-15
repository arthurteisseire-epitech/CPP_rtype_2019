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
#include "TypeProtocol.hpp"
#include "Entity.hpp"

namespace ecs
{
    class EntityFactory {
    public:
        template <typename ...Args>
        static void createEntity(std::shared_ptr<EntityAdmin> &admin, Args &&...args) {
            admin->entities.emplace_back<>(new Entity(admin,
                GetPool<CId>(admin).create(nextId(admin)),
                std::forward<Args>(args)...)
                );
        }

        static void createPlayer(std::shared_ptr<EntityAdmin> &admin, ObjectPool<CConnection>::index connIdx);
        static void createShootingMonster(std::shared_ptr<EntityAdmin> &admin,
                                          ObjectPool<CTransform>::index transformIdx,
                                          ObjectPool<CDirection>::index directionIdx);
        static void createBullet(std::shared_ptr<EntityAdmin> &admin,
                                 ObjectPool<CTransform>::index transformIdx,
                                 ObjectPool<CDirection>::index directionIdx);
        static void createMonster(std::shared_ptr<EntityAdmin> &admin, TypeProtocol::Type type,
                                  const ObjectPool<CDirection>::index &directionIdx,
                                  const ObjectPool<CMoveType>::index &moveTypeIdx,
                                  const ObjectPool<CCollisionDamage>::index &collisionDmgIdx,
                                  const ObjectPool<CCooldown>::index &cooldownIdx,
                                  const ObjectPool<CHealth>::index &healtIdx,
                                  const ObjectPool<CGun>::index &gunIdx,
                                  const ObjectPool<CSpeed>::index &speedIdx);
    private:
        static int id;

        static mut::Vec2f generateRandomPosition();
    };
}

#endif
