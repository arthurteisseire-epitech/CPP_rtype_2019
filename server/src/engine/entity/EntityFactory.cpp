/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** EntityFactory.cpp
*/

#include "EntityFactory.hpp"
#include "Util.hpp"
#include "TransformComponent.hpp"
#include "DirectionComponent.hpp"
#include "InputTuple.hpp"
#include "SendRenderTuple.hpp"
#include "MoveTuple.hpp"

int ecs::EntityFactory::id = 0;

void ecs::EntityFactory::createPlayer(std::shared_ptr<EntityAdmin> &admin,
                                      ObjectPool<ConnectionComponent>::index connIdx)
{
    auto transformIdx = GetPool<TransformComponent>(admin).create();
    auto dirIdx = GetPool<DirectionComponent>(admin).create();
    auto typeIdx = GetPool<TypeComponent>(admin).create("spaceship_normal");
    auto objIdIdx = GetPool<IdComponent>(admin).create(id++);

    admin->entities.emplace_back(
        new Entity(admin,
            GetPool<InputTuple>(admin).move(std::make_tuple(connIdx, transformIdx, dirIdx)),
            GetPool<MoveTuple>(admin).move(std::make_tuple(transformIdx, dirIdx)),
            GetPool<SendRenderTuple>(admin).move(std::make_tuple(connIdx, transformIdx, typeIdx, objIdIdx))
        )
    );
}

void ecs::EntityFactory::createBullet(std::shared_ptr<EntityAdmin> &admin,
                                      ObjectPool<ConnectionComponent>::index connectionIdx,
                                      ObjectPool<TransformComponent>::index transformIdx)
{
    auto directionIdx = GetPool<DirectionComponent>(admin).create();
    auto typeIdx = GetPool<TypeComponent>(admin).create("basic_missile_launch");
    auto objIdIdx = GetPool<IdComponent>(admin).create(id++);

    GetPool<DirectionComponent>(admin).at(directionIdx).setDirection(DirectionComponent::RIGHT);
    admin->entities.emplace_back(
        new Entity(admin,
            GetPool<MoveTuple>(admin).move(std::make_tuple(transformIdx, directionIdx)),
            GetPool<SendRenderTuple>(admin).move(std::make_tuple(connectionIdx, transformIdx, typeIdx, objIdIdx))
        )
    );
}
