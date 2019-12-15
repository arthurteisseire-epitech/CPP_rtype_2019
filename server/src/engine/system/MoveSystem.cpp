/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include "TypeProtocol.hpp"
#include "MoveSystem.hpp"
#include "MoveTuple.hpp"
#include "Util.hpp"

ecs::MoveSystem::MoveSystem(std::shared_ptr<EntityAdmin> admin) :
    ASystem(std::move(admin))
{
}

void ecs::MoveSystem::update(float)
{
    ForEachMatching<MoveTuple>(admin, [this](MoveTuple &t) {

        auto newTransform = get<CTransform>(t).vec + get<CDirection>(t).dir * get<CSpeed>(t).speed;

        if (!(get<CType>(t).name == TypeProtocol::get(TypeProtocol::SHIP_NORMAL) &&
            (newTransform.x <= 0 || newTransform.x >= 1 || newTransform.y <= 0 || newTransform.y >= 1)))
            get<CTransform>(t).vec = newTransform;
    });
}
