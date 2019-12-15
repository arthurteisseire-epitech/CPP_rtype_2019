/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CGun.hpp
*/

#ifndef RTYPE_CGUN_HPP
#define RTYPE_CGUN_HPP

#include "CCooldown.hpp"
#include "CBulletType.hpp"
#include "CHealth.hpp"
#include "CCollisionDamage.hpp"
#include "CMoveType.hpp"

namespace ecs
{
    struct CGun {
        CGun(const CBulletType &type = CBulletType::BASIC, const CSpeed &speed = 5, const CCollisionDamage &damage = 20,
             const CCooldown &cooldown = 2, const CHealth &health = 10, const CMoveType &moveType = CMoveType::STRAIGHT) :
                type(type),
                speed(speed),
                damage(damage),
                cooldown(cooldown),
                health(health),
                moveType(moveType)
             {}

        CBulletType type;
        CSpeed speed;
        CCollisionDamage damage;
        CCooldown cooldown;
        CHealth health;
        CMoveType moveType;
    };
}

#endif
