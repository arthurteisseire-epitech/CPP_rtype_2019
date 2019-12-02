/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CInput.hpp
*/

#ifndef RTYPE_CINPUT_HPP
#define RTYPE_CINPUT_HPP

#include <queue>

namespace ecs
{
    struct CInput {
        enum Key {
            LEFT,
            RIGHT,
            UP,
            DOWN,
            SPACE
        };

        std::vector<Key> inputs;
    };
}

#endif
