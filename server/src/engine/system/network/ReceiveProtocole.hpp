/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ReceiveProtocole.hpp
*/

#ifndef RTYPE_RECEIVEPROTOCOLE_HPP
#define RTYPE_RECEIVEPROTOCOLE_HPP

#include <unordered_map>

namespace ecs
{
    class ReceiveProtocole {
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
        static const std::unordered_map<std::string, Key> commands;
    };
}

#endif
