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
#include "CInput.hpp"
#include "CType.hpp"
#include "CId.hpp"

int ecs::EntityFactory::id = 0;

void ecs::EntityFactory::createPlayer(std::shared_ptr<EntityAdmin> &admin,
                                      ObjectPool<CConnection>::index connIdx)
{
    admin->entities.emplace_back(
        new Entity(admin,
            connIdx,
            GetPool<CTransform>(admin).create(),
            GetPool<CInput>(admin).create(),
            GetPool<CDirection>(admin).create(),
            GetPool<CType>(admin).create("spaceship_normal"),
            GetPool<CId>(admin).create(id++)
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
            GetPool<CId>(admin).create(id++),
            connectionIdx,
            transformIdx,
            directionIdx
        )
    );
}
