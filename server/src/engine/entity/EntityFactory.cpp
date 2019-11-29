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
            GetPool<InputTuple>(admin).move(std::make_tuple(connIdx, transformIdx, dirIdx)),
            GetPool<MoveTuple>(admin).move(std::make_tuple(transformIdx, dirIdx)),
            GetPool<SendRenderTuple>(admin).move(std::make_tuple(connIdx, transformIdx, typeIdx, objIdIdx))
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

    GetPool<CDirection>(admin).at(directionIdx).setDirection(CDirection::RIGHT).setPermanentMovement(true);
    admin->entities.emplace_back(
        new Entity(admin,
            GetPool<MoveTuple>(admin).move(std::make_tuple(transformIdx, directionIdx)),
            GetPool<SendRenderTuple>(admin).move(std::make_tuple(connectionIdx, transformIdx, typeIdx, objIdIdx))
        )
    );
}
