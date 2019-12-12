/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ReceiveProtocol.hpp
*/

#ifndef RTYPE_RECEIVEPROTOCOL_HPP
#define RTYPE_RECEIVEPROTOCOL_HPP

#include <unordered_map>
#include <functional>

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

        static std::pair<ecs::ReceiveProtocol::Key, std::string> find(const std::string &command);
        static std::function<bool(const std::pair<Key, std::string> &pair)> is(Key key);

        template<typename T>
        static bool any(Key key, const T &t)
        {
            return std::any_of(t.begin(), t.end(), [&key](const auto &pair) {return key == pair.first;});
        }

    private:
        static const std::unordered_map<std::string_view, Key> commands;
    };
}

#endif
