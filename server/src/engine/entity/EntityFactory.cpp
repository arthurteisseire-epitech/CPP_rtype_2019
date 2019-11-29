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
    auto transformIdx = GetPool<CTransform>(admin).create();
    auto dirIdx = GetPool<CDirection>(admin).create();
    auto typeIdx = GetPool<CType>(admin).create("spaceship_normal");
    auto objIdIdx = GetPool<CId>(admin).create(id++);

    admin->entities.emplace_back(
        new Entity(admin,
            GetPool<InputTuple>(admin).create(connIdx, transformIdx, dirIdx),
            GetPool<MoveTuple>(admin).create(transformIdx, dirIdx),
            GetPool<SendRenderTuple>(admin).create(connIdx, transformIdx, typeIdx, objIdIdx)
        )
    );
}

void ecs::EntityFactory::createBullet(std::shared_ptr<EntityAdmin> &admin,
                                      ObjectPool<CConnection>::index connectionIdx,
                                      ObjectPool<CTransform>::index transformIdx)
{
    auto directionIdx = GetPool<CDirection>(admin).create();
    auto typeIdx = GetPool<CType>(admin).create("basic_missile_launch");
    auto objIdIdx = GetPool<CId>(admin).create(id++);

    GetPool<CDirection>(admin).at(directionIdx).setDirection(CDirection::RIGHT);
    admin->entities.emplace_back(
        new Entity(admin,
            GetPool<MoveTuple>(admin).create(transformIdx, directionIdx),
            GetPool<SendRenderTuple>(admin).create(connectionIdx, transformIdx, typeIdx, objIdIdx)
        )
    );
}
