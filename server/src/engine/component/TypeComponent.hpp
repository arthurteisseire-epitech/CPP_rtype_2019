/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_TYPECOMPONENT_HPP
#define RTYPE_TYPECOMPONENT_HPP

#include <string>
#include <utility>

namespace ecs
{
    struct TypeComponent {
        explicit TypeComponent(std::string str) : name(std::move(str)) {}
        std::string name;
    };
}

#endif
