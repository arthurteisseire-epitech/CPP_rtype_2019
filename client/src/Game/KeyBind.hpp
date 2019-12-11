/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Vleb
*/

#ifndef RTYPE_KEYBIND_HPP
#define RTYPE_KEYBIND_HPP

#include <map>
#include <SFML/Graphics.hpp>

namespace Client {
    class KeyBind {
    public:
        KeyBind();
        ~KeyBind() = default;
        void rebind(const sf::Keyboard::Key bind, const sf::Keyboard::Key action);
        sf::Keyboard::Key getAction(const sf::Keyboard::Key bind);
        bool isBound(const sf::Keyboard::Key bind);
    private:
        std::map<sf::Keyboard::Key, sf::Keyboard::Key> _bind;
    };
}

#endif
