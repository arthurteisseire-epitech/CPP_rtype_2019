/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_CTYPE_HPP
#define RTYPE_CTYPE_HPP

#include <string>
#include <utility>

namespace ecs
{
    struct CType {
        explicit CType(std::string str) : name(std::move(str)) {}
        std::string name;
    };
}

#endif
