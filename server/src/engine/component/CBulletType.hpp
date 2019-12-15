/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_CBULLETTYPE_HPP
#define RTYPE_CBULLETTYPE_HPP

namespace ecs
{
    struct CBulletType {
        enum BulletType {
            BASIC,
            ENEMY_BASIC
        } type;

        CBulletType(BulletType type) : type(type) {}
    };
}

#endif
