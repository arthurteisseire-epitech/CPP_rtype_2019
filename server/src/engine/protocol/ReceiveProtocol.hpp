/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ReceiveProtocol.hpp
*/

#ifndef RTYPE_RECEIVEPROTOCOL_HPP
#define RTYPE_RECEIVEPROTOCOL_HPP

#include <unordered_map>

namespace ecs
{
    class ReceiveProtocol {
    public:
        enum Key {
            LEFT,
            RIGHT,
            UP,
            DOWN,
            SPACE,
            CONNECT,
            UNKOWN,
        };

        static Key find(const std::string &command);
    private:
        static const std::unordered_map<std::string_view, Key> commands;
    };
}

#endif
