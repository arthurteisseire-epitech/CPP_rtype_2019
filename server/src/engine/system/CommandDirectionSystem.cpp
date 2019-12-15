/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CommandDirectionSystem.cpp
*/

#include <utility>
#include "CommandDirectionSystem.hpp"

const std::map<ecs::ReceiveProtocol::Key, ecs::CDirection::Direction> ecs::CommandDirectionSystem::directions = {
    {ecs::ReceiveProtocol::LEFT, ecs::CDirection::LEFT},
    {ecs::ReceiveProtocol::RIGHT, ecs::CDirection::RIGHT},
    {ecs::ReceiveProtocol::UP, ecs::CDirection::UP},
    {ecs::ReceiveProtocol::DOWN, ecs::CDirection::DOWN}
};

ecs::CommandDirectionSystem::CommandDirectionSystem(std::shared_ptr<EntityAdmin> admin) :
    ASystem(std::move(admin))
{
}

void ecs::CommandDirectionSystem::update(float dt)
{
    ForEachMatching<InputDirectionTuple>(admin, [this](InputDirectionTuple &t) {

        auto &inputs = get<CCommand>(t).commands;
        decltype(get<CCommand>(t).commands) uniqueDir;

        std::copy_if(inputs.begin(), inputs.end(), std::back_inserter(uniqueDir), isKeyADirection);
        std::sort(uniqueDir.begin(), uniqueDir.end());

        uniqueDir.erase(std::unique(uniqueDir.begin(), uniqueDir.end()), uniqueDir.end());

        get<CDirection>(t).resetDir();
        for (auto &d : uniqueDir)
            get<CDirection>(t).addDir(directions.at(d.first));
    });
}

bool ecs::CommandDirectionSystem::isKeyADirection(const std::pair<ReceiveProtocol::Key, std::string> &pair)
{
    return directions.find(pair.first) != directions.end();
}
