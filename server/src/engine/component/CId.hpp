/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_CID_HPP
#define RTYPE_CID_HPP

namespace ecs
{
    struct CId {
        explicit CId(unsigned int id) : id(id) {}
        unsigned int id;
    };
}

#endif
