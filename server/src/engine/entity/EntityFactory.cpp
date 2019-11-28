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

void ecs::EntityFactory::createPlayer(std::shared_ptr<EntityAdmin> &admin, ConnectionComponent *connection)
{
    auto transform = GetPool<TransformComponent>(admin).create();
    auto direction = GetPool<DirectionComponent>(admin).create();
    auto type = GetPool<TypeComponent>(admin).create("spaceship_normal");
    auto objId = GetPool<IdComponent>(admin).create(id++);

    createEntity(admin,
        GetPool<InputTuple>(admin).create(connection, transform, direction),
        GetPool<SendRenderTuple>(admin).create(connection, transform, type, objId),
        GetPool<MoveTuple>(admin).create(transform, direction)
    );
}

void ecs::EntityFactory::createBullet(std::shared_ptr<EntityAdmin> &admin, ConnectionComponent *connection,
                                      TransformComponent *transform)
{
    auto direction = GetPool<DirectionComponent>(admin).create();
    auto type = GetPool<TypeComponent>(admin).create("basic_missile_launch");
    auto objId = GetPool<IdComponent>(admin).create(id++);

    direction->setDirection(DirectionComponent::RIGHT);
    createEntity(admin,
        GetPool<MoveTuple>(admin).create(transform, direction),
        GetPool<SendRenderTuple>(admin).create(connection, transform, type, objId)
    );
}
