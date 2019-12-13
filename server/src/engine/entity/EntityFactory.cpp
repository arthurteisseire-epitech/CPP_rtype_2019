/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** EntityFactory.cpp
*/

#include "EntityFactory.hpp"
#include "Util.hpp"
#include "TypeProtocol.hpp"
#include "Entity.hpp"

#include "CConnection.hpp"
#include "CTransform.hpp"
#include "CDirection.hpp"
#include "CCommand.hpp"
#include "CType.hpp"
#include "CId.hpp"

void ecs::EntityFactory::createPlayer(std::shared_ptr<EntityAdmin> &admin,
                                      ObjectPool<CConnection>::index connIdx)
{
    admin->entities.emplace_back(
        new Entity(admin,
                   connIdx,
                   GetPool<CTransform>(admin).create(mut::Vec2f(0.1f, 0.5f)),
                   GetPool<CCommand>(admin).create(),
                   GetPool<CDirection>(admin).create(),
                   GetPool<CType>(admin).create(TypeProtocol::get(TypeProtocol::SHIP_NORMAL)),
                   GetPool<CSpeed>(admin).create(1),
                   GetPool<CCollisionDamage>(admin).create(20),
                   GetPool<CHealth>(admin).create(100),
                   GetPool<CId>(admin).create(nextId(admin))
        )
    );
}

void ecs::EntityFactory::createBullet(std::shared_ptr<EntityAdmin> &admin,
                                      ObjectPool<CTransform>::index transformIdx,
                                      ObjectPool<CDirection>::index directionIdx)
{
    admin->entities.emplace_back(
        new Entity(admin,
                   GetPool<CType>(admin).create(TypeProtocol::get(TypeProtocol::MISSILE_NORMAL)),
                   GetPool<CId>(admin).create(nextId(admin)),
                   GetPool<CSpeed>(admin).create(5),
                   GetPool<CCollisionDamage>(admin).create(5),
                   GetPool<CHealth>(admin).create(1),
                   transformIdx,
                   directionIdx
        )
    );
}

void ecs::EntityFactory::createShootingMonster(std::shared_ptr<EntityAdmin> &admin,
                                               ecs::ObjectPool<ecs::CTransform>::index transformIdx,
                                               ecs::ObjectPool<ecs::CDirection>::index directionIdx)
{
    admin->entities.emplace_back(
        new Entity(admin,
                   GetPool<CType>(admin).create(TypeProtocol::get(TypeProtocol::MISSILE_NORMAL)),
                   GetPool<CId>(admin).create(nextId(admin)),
                   GetPool<CShootingAI>(admin).create(),
                   GetPool<CCooldown>(admin).create(1),
                   GetPool<CSpeed>(admin).create(2),
                   GetPool<CCollisionDamage>(admin).create(5),
                   GetPool<CHealth>(admin).create(100),
                   transformIdx,
                   directionIdx
        )
    );
}
