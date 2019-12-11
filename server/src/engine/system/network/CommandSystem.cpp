/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CommandSystem.cpp
*/

#include "CommandSystem.hpp"
#include "CCommand.hpp"
#include "CommandTuple.hpp"

ecs::CommandSystem::CommandSystem(std::shared_ptr<EntityAdmin> admin) :
    ASystem(std::move(admin))
{
}

const std::map<std::string, ecs::CCommand::Key> ecs::CommandSystem::directions = {
    {"left", ecs::CCommand::LEFT},
    {"right", ecs::CCommand::RIGHT},
    {"up", ecs::CCommand::UP},
    {"down", ecs::CCommand::DOWN},
    {"space", ecs::CCommand::SPACE},
    {"connect", ecs::CCommand::CONNECT},
};

void ecs::CommandSystem::update(float deltaTime)
{
    ForEachMatching<CommandTuple>(admin, [this](CommandTuple &t) {

        auto &buffers = get<CConnection>(t).readBuffers;

        get<CCommand>(t).commands.clear();
        get<CCommand>(t).commands.reserve(buffers.size());
        while (!buffers.empty()) {
            std::string s(std::begin(buffers.front().data), std::end(buffers.front().data));
            s.erase(std::remove_if(s.begin(), s.end(), iscntrl), s.end());

            auto it = directions.find(s);
            if (it != directions.end())
                get<CCommand>(t).commands.push_back(it->second);
            buffers.pop();
        }
    });
}
