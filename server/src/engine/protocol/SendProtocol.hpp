/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ReceiveProtocol.hpp
*/

#ifndef RTYPE_SENDPROTOCOL_HPP
#define RTYPE_SENDPROTOCOL_HPP

#include <unordered_map>

namespace ecs
{
    class SendProtocol {
    public:
        enum Key {
            CONNECTED,
            ENTITY_SET,
        };

        static std::string_view get(Key key);
    private:
        static const std::unordered_map<Key, std::string_view> commands;
    };
}

#endif
