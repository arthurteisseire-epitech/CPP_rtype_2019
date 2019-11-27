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
    static int currId = 0;
    auto t = GetPool<TransformComponent>(admin).create();
    auto d = GetPool<DirectionComponent>(admin).create();
    auto type = GetPool<TypeComponent>(admin).create("spaceship_normal");
    auto id = GetPool<IdComponent>(admin).create(currId++);

    createEntity(admin,
        GetPool<InputTuple>(admin).create(connection, d),
        GetPool<SendTuple>(admin).create(connection, t, type, id),
        GetPool<MoveTuple>(admin).create(d, t)
    );
}
