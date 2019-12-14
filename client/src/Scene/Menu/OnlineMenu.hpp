/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** OnlineMenu.hpp
*/

#ifndef RTYPE_ONLINEMENU_HPP
#define RTYPE_ONLINEMENU_HPP

#include <array>
#include <vector>
#include "Component/Fading.hpp"
#include "Component/Image.hpp"
#include "Component/Loader.hpp"
#include "Component/Ship.hpp"
#include "Scene/IScene.hpp"

namespace Client {
    class OnlineMenu : public IScene {
    public:
        OnlineMenu(Client::IScene *prev = nullptr);
        ~OnlineMenu() override;
        void event(Client::IScene *&self, sf::Event &event, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window) override;
        void update(Client::IScene *&self, Client::KeyBind &keyBind, Client::Network &network, Client::Window &window) override;
        void render(Client::Window &window) override;
    private:
        Client::IScene *_prev;
        std::vector<Client::IComponent *> _components;
        uint8_t _playerNb;
        sf::Clock _clock;
        float _quitRefTime;
        Client::IScene *_next;
    };
}

#endif