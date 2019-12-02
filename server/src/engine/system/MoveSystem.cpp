/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include "MoveSystem.hpp"
#include "MoveTuple.hpp"
#include "Util.hpp"

ecs::MoveSystem::MoveSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(std::move(admin))
{
}

void ecs::MoveSystem::update(float)
{
    ForEachMatching<MoveTuple>(admin, [this](MoveTuple &t) {

        get<CTransform>(t).vec += get<CDirection>(t).dir;

    });
}
