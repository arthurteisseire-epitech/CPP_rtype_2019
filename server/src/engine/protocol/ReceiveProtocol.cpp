/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ReceiveProtocol.cpp
*/

#include "ReceiveProtocol.hpp"

const std::unordered_map<std::string, ecs::ReceiveProtocol::Key> ecs::ReceiveProtocol::commands = {
    {"action left",    ecs::ReceiveProtocol::LEFT},
    {"action right",   ecs::ReceiveProtocol::RIGHT},
    {"action up",      ecs::ReceiveProtocol::UP},
    {"action down",    ecs::ReceiveProtocol::DOWN},
    {"action space",   ecs::ReceiveProtocol::SPACE},
    {"connect", ecs::ReceiveProtocol::CONNECT},
};

ecs::ReceiveProtocol::Key ecs::ReceiveProtocol::find(const std::string &command)
{
    auto it = commands.find(command);
    if (it == commands.end())
        return UNKOWN;
    return it->second;
}
