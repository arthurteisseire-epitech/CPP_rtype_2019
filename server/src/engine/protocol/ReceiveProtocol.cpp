/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ReceiveProtocol.cpp
*/

#include <iostream>
#include "ReceiveProtocol.hpp"

const std::unordered_map<std::string_view, ecs::ReceiveProtocol::Key> ecs::ReceiveProtocol::commands = {
    {"action_left",    ecs::ReceiveProtocol::LEFT},
    {"action_right",   ecs::ReceiveProtocol::RIGHT},
    {"action_up",      ecs::ReceiveProtocol::UP},
    {"action_down",    ecs::ReceiveProtocol::DOWN},
    {"action_space",   ecs::ReceiveProtocol::SPACE},
    {"connect", ecs::ReceiveProtocol::CONNECT},
    {"disconnect", ecs::ReceiveProtocol::DISCONNECT},
    {"entity_collision", ecs::ReceiveProtocol::COLLISION},
    {"game_request", ecs::ReceiveProtocol::GAME_REQUEST},
    {"game_start", ecs::ReceiveProtocol::GAME_START},
};

std::pair<ecs::ReceiveProtocol::Key, std::string> ecs::ReceiveProtocol::find(const std::string &command)
{
    auto keyString = command.substr(0, command.find(':'));
    auto it = commands.find(keyString);
    if (it == commands.end())
        return {UNKOWN, ""};
    return {it->second, command.substr(std::min(command.length(), keyString.length() + 1))};
}
