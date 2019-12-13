/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** MainMenu.hpp
*/

#ifndef RTYPE_GAME_HPP
#define RTYPE_GAME_HPP

#include "Component/Ship.hpp"
#include "IScene.hpp"

namespace Client {
    class Game : public IScene {
    public:
        Game(Client::IScene *prev = nullptr);
        Game(std::array<Client::Ship *, 4> &players, Client::IScene *prev = nullptr);
        ~Game() override;
        void event(Client::IScene *&self, sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window) override;
        void update(Client::IScene *&self, Client::Network &network, Client::Window &window) override;
        void render(Client::Window &window) override;
        void deleteEntity(const std::vector<std::string> &payload, const uint32_t &id);
        void setEntity(const std::vector<std::string> &payload, const uint32_t &id);
    private:
        Client::IScene *_prev;
        std::vector<Client::IComponent *> _components;
        bool _start;
    };
}

#endif