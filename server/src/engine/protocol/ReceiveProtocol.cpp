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

std::pair<ecs::ReceiveProtocol::Key, std::string> ecs::ReceiveProtocol::find(const std::string &command)
{
    auto keyString = command.substr(0, command.find(' '));
    auto it = commands.find(keyString);
    if (it == commands.end())
        return {UNKOWN, ""};
    return {it->second, command.substr(std::min(command.length(), keyString.length() + 1))};
}
