/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ReceiveProtocole.cpp
*/

#include "ReceiveProtocole.hpp"

const std::unordered_map<std::string, ecs::ReceiveProtocole::Key> ecs::ReceiveProtocole::commands = {
    {"left",    ecs::ReceiveProtocole::LEFT},
    {"right",   ecs::ReceiveProtocole::RIGHT},
    {"up",      ecs::ReceiveProtocole::UP},
    {"down",    ecs::ReceiveProtocole::DOWN},
    {"space",   ecs::ReceiveProtocole::SPACE},
    {"connect", ecs::ReceiveProtocole::CONNECT},
};

ecs::ReceiveProtocole::Key ecs::ReceiveProtocole::find(const std::string &command)
{
    auto it = commands.find(command);
    if (it == commands.end())
        return UNKOWN;
    return it->second;
}
