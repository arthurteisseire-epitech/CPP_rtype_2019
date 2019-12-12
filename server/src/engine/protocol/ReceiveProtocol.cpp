/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ReceiveProtocol.cpp
*/

#include "ReceiveProtocol.hpp"

const std::unordered_map<std::string_view, ecs::ReceiveProtocol::Key> ecs::ReceiveProtocol::commands = {
    {"left",    ecs::ReceiveProtocol::LEFT},
    {"right",   ecs::ReceiveProtocol::RIGHT},
    {"up",      ecs::ReceiveProtocol::UP},
    {"down",    ecs::ReceiveProtocol::DOWN},
    {"space",   ecs::ReceiveProtocol::SPACE},
    {"connect", ecs::ReceiveProtocol::CONNECT},
};

ecs::ReceiveProtocol::Key ecs::ReceiveProtocol::find(const std::string &command)
{
    auto it = commands.find(command);
    if (it == commands.end())
        return UNKOWN;
    return it->second;
}
