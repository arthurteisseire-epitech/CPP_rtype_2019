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
        void update(Client::IScene *&self, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window) override;
        void render(Client::Window &window) override;
        void deleteEntity(const std::vector<std::string> &payload, const uint32_t &id);
        void setEntity(const std::vector<std::string> &payload, const uint32_t &id);
        void pauseMenu(Client::IScene *&self, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window);
    private:
        void play(Client::Network &network, Client::Window &window);
        void menu(Client::Network &network, Client::Window &window);
        void quit(Client::Network &network, Client::Window &window);
        enum Status {init, run, pause};
        Client::IScene *_prev;
        std::vector<Client::IComponent *> _components;
        std::vector<std::pair<Client::IComponent *, void (Client::Game::*)(Client::Network &, Client::Window &)>> _pauseComponents;
        Client::Game::Status _status;
        sf::Clock _clock;
        float _quitRefTime;
        Client::IScene *_next;
    };
}

#endif