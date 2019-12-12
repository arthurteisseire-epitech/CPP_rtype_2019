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
        explicit CType(std::string_view str) : name(str) {}
        std::string_view name;
    };
}

#endif
