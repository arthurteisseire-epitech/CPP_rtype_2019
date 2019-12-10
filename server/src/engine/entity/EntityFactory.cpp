/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** EntityFactory.cpp
*/

#include "EntityFactory.hpp"
#include "Util.hpp"

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
            GetPool<CTransform>(admin).create(),
            GetPool<CCommand>(admin).create(),
            GetPool<CDirection>(admin).create(),
            GetPool<CType>(admin).create("spaceship_normal"),
            GetPool<CId>(admin).create(nextId(admin))
        )
    );
}

void ecs::EntityFactory::createBullet(std::shared_ptr<EntityAdmin> &admin,
                                      ObjectPool<CConnection>::index connectionIdx,
                                      ObjectPool<CTransform>::index transformIdx,
                                      ObjectPool<CDirection>::index directionIdx)
{
    admin->entities.emplace_back(
        new Entity(admin,
            GetPool<CType>(admin).create("basic_missile_launch"),
            GetPool<CId>(admin).create(nextId(admin)),
            connectionIdx,
            transformIdx,
            directionIdx
        )
    );
}
