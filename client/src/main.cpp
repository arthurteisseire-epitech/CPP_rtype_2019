/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** main.cpp
*/

#include <iostream>
#include <sstream>
#include <utility>
#include "Game/KeyBind.hpp"
#include "Game/Window.hpp"
#include "Network/Network.hpp"
#include "Scene/Menu/MainMenu.hpp"

std::pair<std::string, uint16_t> parseArgs(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        std::string argument(av[i]);
        if (argument == "-h" || argument == "--help") {
            std::cout << "Usage:\t./r-type_client [serverIp] clientPort" << std::endl;
            std::cout << "\tserverIp\t(OPTIONAL) The IPv4 the client will use to communicate with the server." << std::endl;
            std::cout << "\tclientPort\tThe port which will be used to receive the server packets." << std::endl;
            std::exit(0);
        }
    }
    std::string serverIp;
    int64_t clientPort;
    if (ac == 2) {
        serverIp = "127.0.0.1";
        try {
            clientPort = std::stoi(av[1]);
        } catch (std::logic_error &invalidArgument) {
            throw std::runtime_error(std::string("\'parseArgs\': Cannot parse the port: ") + av[1]);
        }
    } else if (ac == 3) {
        serverIp = av[1];
        try {
            std::istringstream ipStream(serverIp);
            std::string subIpStr;
            int ipSize = 0;
            while (std::getline(ipStream, subIpStr, '.')) {
                int64_t subIp(std::stoi(subIpStr));
                if (subIpStr.empty() || subIp < 0 || subIp > 255) {
                    throw std::logic_error("");
                }
                ipSize++;
            }
            if (ipSize != 4 || serverIp[serverIp.size() - 1] == '.') {
                throw std::logic_error("");
            }
        } catch (std::logic_error &invalidArgument) {
            throw std::runtime_error(std::string("\'parseArgs\': The given IPv4 is invalid: ") + av[1]);
        }
        try {
            clientPort = std::stoi(av[2]);
        } catch (std::logic_error &invalidArgument) {
            throw std::runtime_error(std::string("\'parseArgs\': Cannot parse the port: ") + av[2]);
        }
    } else {
        throw std::runtime_error("\'parseArgs\': This program requires at least 1 argument at launch. Please retry with -h or --help for more information.");
    }
    if (clientPort < 0 || clientPort > 65535 || clientPort == SERVER_PORT) {
        throw std::runtime_error("\'parseArgs\': The given port is invalid.");
    }
    return {serverIp, clientPort};
}

int main(int ac, char **av)
{
    Client::IScene *scene = nullptr;
    try {
        std::pair<std::string, uint16_t> networkSettings(parseArgs(ac, av));
        scene = new Client::MainMenu();
        Client::KeyBind keyBind;
        Client::Network network(networkSettings.first, networkSettings.second);
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