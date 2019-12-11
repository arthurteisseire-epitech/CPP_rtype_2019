/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CommandDirectionSystem.cpp
*/

#include <utility>
#include "CommandDirectionSystem.hpp"

const std::map<ecs::CCommand::Key, ecs::CDirection::Direction> ecs::CommandDirectionSystem::directions = {
    {ecs::CCommand::LEFT, ecs::CDirection::LEFT},
    {ecs::CCommand::RIGHT, ecs::CDirection::RIGHT},
    {ecs::CCommand::UP, ecs::CDirection::UP},
    {ecs::CCommand::DOWN, ecs::CDirection::DOWN}
};

ecs::CommandDirectionSystem::CommandDirectionSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(std::move(admin))
{
}

void ecs::CommandDirectionSystem::update(float dt)
{
    ForEachMatching<InputDirectionTuple>(admin, [this] (InputDirectionTuple &t) {

        auto dir = CDirection::NONE;
        auto &inputs = get<CCommand>(t).commands;

        auto it = std::find_if(inputs.begin(), inputs.end(), &isKeyADirection);
        if (it != inputs.end())
            dir = directions.at(*it);
        get<CDirection>(t).setDirection(dir);
    });
}

bool ecs::CommandDirectionSystem::isKeyADirection(ecs::CCommand::Key key)
{
    return directions.find(key) != directions.end();
}
