/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** MainMenu.hpp
*/

#ifndef RTYPE_MAINMENU_HPP
#define RTYPE_MAINMENU_HPP

#include <utility>
#include <vector>
#include "Component/Button.hpp"
#include "Component/Image.hpp"
#include "Scene/IScene.hpp"

namespace Client {
    class MainMenu : public IScene {
    public:
        MainMenu(Client::IScene *prev = nullptr);
        ~MainMenu() override;
        void event(Client::IScene *&self, sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window) override;
        void update(Client::IScene *&self, Client::Network &network, Client::Window &window) override;
        void render(Client::Window &window) override;
    private:
        void play(Client::Window &window);
        void options(Client::Window &window);
        void quit(Client::Window &window);
        Client::IScene *_prev;
        std::vector<Client::IComponent *> _components;
        std::vector<std::pair<Client::Button *, void (Client::MainMenu::*)(Client::Window &)>> _buttons;
        sf::Clock _clock;
        float _quitRefTime;
        Client::IScene *_next;
    };
}

#endif