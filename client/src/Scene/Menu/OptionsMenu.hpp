/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** OptionsMenu.hpp
*/

#ifndef RTYPE_OPTIONSMENU_HPP
#define RTYPE_OPTIONSMENU_HPP

#include <utility>
#include <vector>
#include "Component/Button.hpp"
#include "Component/Image.hpp"
#include "Scene/IScene.hpp"

namespace Client {
    class OptionsMenu : public IScene {
    public:
        OptionsMenu(const Client::Window &window, Client::IScene *prev = nullptr);
        ~OptionsMenu() override;
        void event(Client::IScene *&self, sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window) override;
        void update(Client::IScene *&self, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window) override;
        void render(Client::Window &window) override;
    private:
        void sound(Client::Window &window);
        void vsync(Client::Window &window);
        void back(Client::Window &window);
        Client::IScene *_prev;
        std::vector<Client::IComponent *> _components;
        std::vector<std::pair<Client::Button *, void (Client::OptionsMenu::*)(Client::Window &)>> _buttons;
        sf::Clock _clock;
        float _quitRefTime;
        Client::IScene *_next;
    };
}

#endif