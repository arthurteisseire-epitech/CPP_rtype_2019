/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include <utility>
#include "Util.hpp"
#include "UpdateTypeSystem.hpp"

const std::unordered_map<std::string, std::string> ecs::UpdateTypeSystem::nextType = {
    {"basic_missile_launch", "basic_missile_launch_2"},
    {"basic_missile_launch_2", "basic_missile_launched"},
    {"basic_missile_launch_2_rev", "basic_missile_launched_rev"},
    {"basic_missile_launch_rev", "basic_missile_launch_2_rev"}
};

ecs::UpdateTypeSystem::UpdateTypeSystem(std::shared_ptr<EntityAdmin> admin) :
    ASystem(std::move(admin))
{
}

void ecs::UpdateTypeSystem::update(float)
{
    ForEachMatching<CType>(admin, [this](CType &t) {
        auto res = nextType.find(t.name);
        if (res != nextType.end())
            t.name = res->second;
    });
}
