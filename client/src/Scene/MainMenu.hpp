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
#include "IScene.hpp"

namespace Client {
    class MainMenu : public IScene {
    public:
        MainMenu();
        ~MainMenu() override;
        void event(Client::IScene *&self, sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window) override;
        void update(Client::IScene *&self, Client::Network &network, Client::Window &window) override;
        void render(Client::Window &window) override;
    private:
        void play(Client::IScene *&self);
        void options(Client::IScene *&self);
        void quit(Client::IScene *&self);
        std::vector<Client::Image *> _sprites;
        std::vector<std::pair<Client::Button *, void (Client::MainMenu::*)(Client::IScene *&)>> _buttons;
        sf::Clock _clock;
        float _quitRefTime;
    };
}

#endif