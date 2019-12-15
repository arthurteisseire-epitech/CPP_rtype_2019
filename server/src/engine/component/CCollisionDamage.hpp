/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CCollisionDamage.hpp
*/

#ifndef RTYPE_CCOLLISIONDAMAGE_HPP
#define RTYPE_CCOLLISIONDAMAGE_HPP

namespace ecs
{
    struct CCollisionDamage {
        CCollisionDamage(int _damage) :
            damage(_damage)
        {
        }

        int damage;
    };
}

#endif
