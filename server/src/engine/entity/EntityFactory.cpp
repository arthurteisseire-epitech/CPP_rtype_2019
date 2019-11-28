/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** EntityFactory.cpp
*/

#include "EntityFactory.hpp"
#include "DirectionComponent.hpp"
#include "SendTuple.hpp"
#include "PlayerEntity.hpp"

void ecs::EntityFactory::createPlayer(std::shared_ptr<EntityAdmin> &admin, ObjectPool<ConnectionComponent>::index idx)
{
    admin->entities.emplace_back(new PlayerEntity(admin, idx));
}
