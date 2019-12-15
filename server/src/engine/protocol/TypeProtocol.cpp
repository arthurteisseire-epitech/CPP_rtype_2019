/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** TypeProtocol.cpp
*/

#include "TypeProtocol.hpp"

const std::unordered_map<ecs::TypeProtocol::Type, std::string_view> ecs::TypeProtocol::types = {
    {ecs::TypeProtocol::SHIP_NORMAL, "ship"},
    {ecs::TypeProtocol::ENEMY_SHIP, "enemy_ship1"},
    {ecs::TypeProtocol::ENEMY_SHIP2, "enemy_ship2"},
    {ecs::TypeProtocol::ALIEN, "alien1"},
    {ecs::TypeProtocol::ALIEN2, "alien2"},
    {ecs::TypeProtocol::MISSILE_STAGE1, "blast_stage1"},
    {ecs::TypeProtocol::MISSILE_STAGE2, "blast_stage2"},
    {ecs::TypeProtocol::MISSILE_STAGE3, "blast_stage3"},
    {ecs::TypeProtocol::ENEMY_BLAST_STAGE1, "enemy_blast_stage3"},
    {ecs::TypeProtocol::ENEMY_BLAST_STAGE2, "enemy_blast_stage3"},
    {ecs::TypeProtocol::ENEMY_BLAST_STAGE3, "enemy_blast_stage3"},
    {ecs::TypeProtocol::VORTEX, "vortex"},
    {ecs::TypeProtocol::POWERUP, "power_up"},
};

const std::unordered_map<ecs::CBulletType::BulletType, ecs::TypeProtocol::Type> ecs::TypeProtocol::bulletTypes = {
    {CBulletType::BASIC, TypeProtocol::MISSILE_STAGE3},
    {CBulletType::ENEMY_BASIC, TypeProtocol::ENEMY_BLAST_STAGE3},
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
