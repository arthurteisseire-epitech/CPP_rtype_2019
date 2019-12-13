/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** DestroyOobSystem.cpp
*/

#include <utility>
#include "DestroyOOBSystem.hpp"
#include "DestroyOOBTuple.hpp"
#include "EntityUtil.hpp"

ecs::DestroyOOBSystem::DestroyOOBSystem(std::shared_ptr<EntityAdmin> admin) :
    ASystem(std::move(admin))
{
}

void ecs::DestroyOOBSystem::update(float)
{
    ForEachMatching<DestroyOOBTuple>(admin, [this] (DestroyOOBTuple &t) {
        auto &vec = get<CTransform>(t).vec;

        if (!(vec.x >= 0 && vec.x <= 1 && vec.y >= 0 && vec.y <= 1))
            EntityUtil::DestroyEntity(admin, get<CId>(t).id);
    });
}
