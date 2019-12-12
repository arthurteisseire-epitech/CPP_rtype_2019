/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** TypeProtocol.cpp
*/

#include "TypeProtocol.hpp"

const std::unordered_map<ecs::TypeProtocol::Type, std::string_view> ecs::TypeProtocol::types = {
    {ecs::TypeProtocol::SHIP_NORMAL, "ship:normal"},
    {ecs::TypeProtocol::SHIP_INVERTED, "ship:inverted"},
    {ecs::TypeProtocol::MISSILE_NORMAL, "missile:normal"},
};

std::string_view ecs::TypeProtocol::get(ecs::TypeProtocol::Type type)
{
    return types.at(type);
}
