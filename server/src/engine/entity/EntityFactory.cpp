/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** EntityFactory.cpp
*/

#include "Util.hpp"
#include "EntityFactory.hpp"
#include "DirectionComponent.hpp"
#include "SendTuple.hpp"

void ecs::EntityFactory::createPlayer(std::shared_ptr<EntityAdmin> &admin,
                                      ObjectPool<ConnectionComponent>::index connIdx)
{
    auto transformIdx = GetPool<TransformComponent>(admin).create();
    auto dirIdx = GetPool<DirectionComponent>(admin).create();

    admin->entities.emplace_back(
        new Entity(admin,
            GetPool<InputTuple>(admin).create(connIdx, dirIdx),
            GetPool<MoveTuple>(admin).create(dirIdx, transformIdx),
            GetPool<SendTuple>(admin).create(connIdx, transformIdx)
        )
    );
}
