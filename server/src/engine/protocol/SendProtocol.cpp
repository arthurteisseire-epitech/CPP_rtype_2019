/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SendProtocol.cpp
*/

#include "SendProtocol.hpp"

const std::unordered_map<ecs::SendProtocol::Key, std::string_view> ecs::SendProtocol::commands = {
    {ecs::SendProtocol::NEW_CONNECTION, "new player"},
    {ecs::SendProtocol::CONNECTED, "connected"},
};

std::string_view ecs::SendProtocol::get(ecs::SendProtocol::Key key)
{
    return commands.at(key);
}
