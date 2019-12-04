/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Game.hpp
*/

#ifndef RTYPE_GAME_HPP
#define RTYPE_GAME_HPP

#include "IScene.hpp"

namespace Client {
    class Game : public IScene {
    public:
        Game();
        ~Game() override;
        void event(Client::IScene *&self, sf::Event &event, Client::KeyBind &keyBind, Client::Network &network) override;
        void update(Client::IScene *&self, Client::Network &network, Client::Window &window) override;
        void render(Client::Window &window) override;
    private:
    };
}

#endif