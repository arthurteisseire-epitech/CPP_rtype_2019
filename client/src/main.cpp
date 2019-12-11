/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** main.cpp
*/

#include <iostream>
#include "Game/KeyBind.hpp"
#include "Game/Window.hpp"
#include "Network/Network.hpp"
#include "Scene/Menu/MainMenu.hpp"

int main(int ac, char **av)
{
    Client::IScene *scene = nullptr;
    try {
        scene = new Client::MainMenu();
        Client::KeyBind keyBind;
        Client::Network network(av[1], std::stoi(av[2]));
        Client::Window window;
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                scene->event(scene, event, keyBind, network, window);
            }
            scene->update(scene, network, window);
            window.clear();
            scene->render(window);
            window.display();
        }
    } catch (std::exception &error) {
        std::cerr << "ERROR: "<< error.what() << std::endl;
        delete scene;
        return 84;
    }
    delete scene;
    return 0;
}