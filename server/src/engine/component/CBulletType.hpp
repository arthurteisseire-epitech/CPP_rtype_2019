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
        enum BULLET_TYPE {
            BASIC
        } type;

        explicit CBulletType(BULLET_TYPE type) : type(type) {}
    };
}

#endif
