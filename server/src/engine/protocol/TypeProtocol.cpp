/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** TypeProtocol.cpp
*/

#include "TypeProtocol.hpp"

const std::unordered_map<ecs::TypeProtocol::Type, std::string_view> ecs::TypeProtocol::types = {
    {ecs::TypeProtocol::SHIP_NORMAL, "player_ship"},
    {ecs::TypeProtocol::PLAYER_LASER, "player_laser"},

    {ecs::TypeProtocol::ENEMY_SHIP, "enemy_ship1"},
    {ecs::TypeProtocol::ENEMY_SHIP2, "enemy_ship2"},

    {ecs::TypeProtocol::ALIEN, "enemy_alien1"},
    {ecs::TypeProtocol::ALIEN2, "enemy_alien2"},

    {ecs::TypeProtocol::ENEMY_BLAST1_STAGE1, "enemy_blast1_stage3"},
    {ecs::TypeProtocol::ENEMY_BLAST1_STAGE2, "enemy_blast1_stage3"},
    {ecs::TypeProtocol::ENEMY_BLAST1_STAGE3, "enemy_blast1_stage3"},

    {ecs::TypeProtocol::VORTEX, "enemy_vortex"},

    {ecs::TypeProtocol::POWERUP, "power_up"},
};

const std::unordered_map<ecs::CBulletType::BulletType, ecs::TypeProtocol::Type> ecs::TypeProtocol::bulletTypes = {
    {CBulletType::BASIC, TypeProtocol::PLAYER_LASER},
    {CBulletType::ENEMY_BASIC, TypeProtocol::ENEMY_BLAST1_STAGE3},
    {CBulletType::VORTEX, TypeProtocol::VORTEX}
};

std::string_view ecs::TypeProtocol::get(ecs::TypeProtocol::Type type)
{
    return types.at(type);
}

std::string_view ecs::TypeProtocol::get(ecs::CBulletType::BulletType type)
{
    return types.at(bulletTypes.at(type));
}
