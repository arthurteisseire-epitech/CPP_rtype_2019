/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CCommand.hpp
*/

#ifndef RTYPE_CCOMMAND_HPP
#define RTYPE_CCOMMAND_HPP

#include <queue>

namespace ecs
{
    struct CCommand {
        enum Key {
            LEFT,
            RIGHT,
            UP,
            DOWN,
            SPACE,
            CONNECT
        };

        std::vector<Key> commands;
    };
}

#endif
