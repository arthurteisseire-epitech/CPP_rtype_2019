/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** TypeProtocol.cpp
*/

#include "TypeProtocol.hpp"

const std::unordered_map<ecs::TypeProtocol::Type, std::string_view> ecs::TypeProtocol::types = {
    {ecs::TypeProtocol::SHIP_NORMAL, "ship"},
    {ecs::TypeProtocol::SHIP_INVERTED, "alien1"},
    {ecs::TypeProtocol::MISSILE_NORMAL, "blast_stage3"},
    {ecs::TypeProtocol::ENEMY_BLAST, "enemy_blast_stage3"},
};

const std::unordered_map<ecs::CBulletType::BulletType, ecs::TypeProtocol::Type> ecs::TypeProtocol::bulletTypes = {
    {CBulletType::BASIC, TypeProtocol::MISSILE_NORMAL},
    {CBulletType::ENEMY_BASIC, TypeProtocol::ENEMY_BLAST}
};

std::string_view ecs::TypeProtocol::get(ecs::TypeProtocol::Type type)
{
    return types.at(type);
}

std::string_view ecs::TypeProtocol::get(ecs::CBulletType::BulletType type)
{
    return types.at(bulletTypes.at(type));
}
