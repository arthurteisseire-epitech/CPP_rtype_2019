/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** main.cpp
*/

#include "Game/KeyBind.hpp"
#include "Game/Window.hpp"
#include "Network/Network.hpp"
#include "Scene/Game.hpp"
#include "Scene/MainMenu.hpp"

int main(int ac, char **av)
{
    Client::IScene *scene = new Client::MainMenu();
    Client::KeyBind keyBind;
    Client::Network network("127.0.0.1", 1234);
    Client::Window window;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            scene->event(scene, event, keyBind, network, window);
        }
        scene->update(scene, network, window);
        window.clear();
        scene->render(window);
        window.display();
    }
    return 0;
}
