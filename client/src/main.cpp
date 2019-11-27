/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** main.cpp
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "INetwork.hpp"
#include "sfNetwork.hpp"
#include "GameSprite.hpp"

void handle_events(game::INetwork *network, sf::RenderWindow &window)
{
    size_t sent;
    sf::Event event{};
    static const std::vector<std::pair<sf::Keyboard::Key, std::string>> keys = {
        {sf::Keyboard::Left, "left"},
        {sf::Keyboard::Right, "right"},
        {sf::Keyboard::Up, "up"},
        {sf::Keyboard::Down, "down"}
    };

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed) {
            for (auto &key : keys)
                if (sf::Keyboard::isKeyPressed(key.first))
                    network->send(key.second.c_str(), key.second.length(), sent);
        }
    }
}

int display(game::INetwork *network)
{
    game::GameSprite gameSprite;
    sf::RenderWindow window(sf::VideoMode(200, 200), "r_type");
    sf::Sprite spaceShip = gameSprite.getSpriteOfType(game::GameSprite::SPACESHIP_NORMAL);
    sf::Sprite missile = gameSprite.getSpriteOfType(game::GameSprite::BASIC_MISSILE_LAUNCHED);
    char data[1024] = {0};

    while (window.isOpen()) {
        handle_events(network, window);

        std::size_t received = 0;
        if (network->receive(&data, sizeof(data), received)) {
            std::cout << "\"" << data << "\"" << std::endl;
            size_t x_pos = std::string(data).find("x:");
            size_t y_pos = std::string(data).find("y:");
            if (x_pos != std::string::npos && y_pos != std::string::npos) {
                x_pos += sizeof("x");
                y_pos += sizeof("y");
                spaceShip.setPosition(std::stof(data + x_pos) * 10, std::stof(data + y_pos) * 10);
                std::cout << "set position:" << std::stof(data + x_pos) << ", " << std::stof(data + y_pos) << std::endl;
            }
        }
        window.clear();
        window.draw(spaceShip);
        window.draw(missile);
        window.display();
    }
    network->disconnect();
    std::cout << "client closed" << std::endl;
    return 0;
}

int main()
{
    game::INetwork *network = new game::sfNetwork();
    if (!network->connect("127.0.0.1", 1234)) {
        std::cerr << "failed to connect" << std::endl;
        return 84;
    }
    return display(network);
}
