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

namespace ecs
{
    class TypeProtocol {
    public:
        enum Type {
            SHIP_NORMAL,
            SHIP_INVERTED,
            MISSILE_NORMAL,
        };

        static std::string_view get(Type type);
    private:
        static const std::unordered_map<Type, std::string_view> types;
    };
}

#endif
