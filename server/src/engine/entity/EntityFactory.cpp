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
#include "SendTuple.hpp"
#include "MoveTuple.hpp"

void ecs::EntityFactory::createPlayer(std::shared_ptr<EntityAdmin> &admin, ConnectionComponent *connection)
{
    auto t = GetPool<TransformComponent>(admin).create();
    auto d = GetPool<DirectionComponent>(admin).create();

    createEntity(admin,
        GetPool<InputTuple>(admin).create(connection, d),
        GetPool<SendTuple>(admin).create(connection, t),
        GetPool<MoveTuple>(admin).create(d, t)
    );
}
