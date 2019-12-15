/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SendProtocol.cpp
*/

#include "SendProtocol.hpp"

const std::unordered_map<ecs::SendProtocol::Key, std::string_view> ecs::SendProtocol::commands = {
    {ecs::SendProtocol::CONNECTED, "player_connected"},
    {ecs::SendProtocol::MATE_CONNECTED, "mate_connected"},
    {ecs::SendProtocol::MATE_DISCONNECTED, "mate_disconnected"},
    {ecs::SendProtocol::ENTITY_SET, "entity_set"},
    {ecs::SendProtocol::ENTITY_DESTROY, "entity_delete"},
};

std::string_view ecs::SendProtocol::get(ecs::SendProtocol::Key key)
{
    return commands.at(key);
}

std::string ecs::SendProtocol::entitySetToString(std::string_view type, float x, float y, float lifeRatio)
{
    return
        std::string(SendProtocol::get(SendProtocol::ENTITY_SET)) + ':' +
            std::string(type) + ':' +
            std::to_string(x) + ',' +
            std::to_string(y) + ':' +
            std::to_string(lifeRatio);
}
