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
            MATE_CONNECTED,
            MATE_DISCONNECTED,
            ENTITY_SET,
            ENTITY_DESTROY,
        };

        static std::string_view get(Key key);
        static std::string entitySetToString(std::string_view type, float x, float y, float lifeRatio);
    private:
        static const std::unordered_map<Key, std::string_view> commands;
    };
}

#endif
