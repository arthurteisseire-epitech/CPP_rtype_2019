/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** EntityFactory.cpp
*/

#include "EntityFactory.hpp"
#include "Util.hpp"
#include "CTransform.hpp"
#include "CDirection.hpp"
#include "InputTuple.hpp"
#include "SendRenderTuple.hpp"
#include "MoveTuple.hpp"

int ecs::EntityFactory::id = 0;

void ecs::EntityFactory::createPlayer(std::shared_ptr<EntityAdmin> &admin,
                                      ObjectPool<CConnection>::index connIdx)
{
    admin->entities.emplace_back(
        new Entity(admin,
            connIdx,
            GetPool<CTransform>(admin).create(),
            GetPool<CDirection>(admin).create(),
            GetPool<CType>(admin).create("spaceship_normal"),
            GetPool<CId>(admin).create(id++)
        )
    );
}

void ecs::EntityFactory::createBullet(std::shared_ptr<EntityAdmin> &admin,
                                      ObjectPool<CConnection>::index connectionIdx,
                                      ObjectPool<CTransform>::index transformIdx)
{
    auto directionIdx = GetPool<CDirection>(admin).create();

    GetPool<CDirection>(admin).at(directionIdx).setDirection(CDirection::RIGHT).setPermanentMovement(true);
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
