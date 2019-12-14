/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_CMOVETYPE_HPP
#define RTYPE_CMOVETYPE_HPP

namespace ecs
{
    struct CMoveType {
        enum MOVE_TYPE {
            STRAIGHT,
            RANDOM,
            SIN,
            NONE,
        } type;

        explicit CMoveType(MOVE_TYPE type) : type(type) {}
    };
}

#endif
