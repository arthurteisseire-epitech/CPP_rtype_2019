/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Menu.hpp
*/

#ifndef RTYPE_MENU_HPP
#define RTYPE_MENU_HPP

#include "IScene.hpp"

namespace Client {
    class Menu : public IScene {
    public:
        Menu();
        ~Menu() override;
        void getEvent(IScene *&self, INetwork &network, sf::RenderWindow &window) override;
        void update(IScene *&self, INetwork &network, sf::RenderWindow &window) override;
    private:
    };
}

#endif