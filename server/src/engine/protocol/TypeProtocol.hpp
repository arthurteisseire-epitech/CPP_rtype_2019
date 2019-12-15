/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** TypeProtocol.hpp
*/

#ifndef RTYPE_TYPEPROTOCOL_HPP
#define RTYPE_TYPEPROTOCOL_HPP

#include <unordered_map>
#include <string_view>
#include "CBulletType.hpp"

namespace ecs
{
    class TypeProtocol {
    public:
        enum Type {
            SHIP_NORMAL,
            ENEMY_SHIP,
            ENEMY_SHIP2,
            ALIEN,
            ALIEN2,
            PLAYER_LASER,
            ENEMY_BLAST1_STAGE1,
            ENEMY_BLAST1_STAGE2,
            ENEMY_BLAST1_STAGE3,
            VORTEX,
            POWERUP
        };

        static std::string_view get(Type type);
        static std::string_view get(CBulletType::BulletType type);
    private:
        static const std::unordered_map<Type, std::string_view> types;
        static const std::unordered_map<CBulletType::BulletType, Type> bulletTypes;
    };
}

#endif
