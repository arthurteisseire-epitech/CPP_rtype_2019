/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** main.cpp
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include <regex>
#include "INetwork.hpp"
#include "sfNetwork.hpp"
#include "GameSprite.hpp"
#include "Buffer.hpp"

void handle_events(game::INetwork *network, sf::RenderWindow &window)
{
    size_t sent;
    sf::Event event{};
    static const std::vector<std::pair<sf::Keyboard::Key, std::string>> keys = {{sf::Keyboard::Left, "left"},
        {sf::Keyboard::Right, "right"}, {sf::Keyboard::Up, "up"}, {sf::Keyboard::Down, "down"},
        {sf::Keyboard::Space, "space"}, {sf::Keyboard::R, "r"}};

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed) {
            for (auto &key : keys)
                if (sf::Keyboard::isKeyPressed(key.first)) {
                    game::Buffer data(0, key.second);
                    network->send(&data, sizeof(data), sent);
                }
        }
    }
}

void handleServerInstructions(game::GameSprite &gameSprite, sf::RenderWindow &window, game::Buffer data,
                              std::unordered_map<int, std::pair<game::GameSprite::Type, sf::Sprite>> &toDraw)
{
    std::string dataStr(data.data.begin(), data.data.end());
    std::cmatch match;

    std::cout << "received: \"" << dataStr.c_str() << "\"" << std::endl;
    if (!std::regex_match(dataStr.c_str(), match, std::regex("(.+?):([-+]?[0-9]*\\.?[0-9]+),([-+]?[0-9]*\\.?[0-9]+)"))) {
        std::cerr << "did not match buffer" << std::endl;
        return;
    }

    const unsigned int id = data.id;
    const std::string typeStr = match[1];
    const float x = std::stof(match[2]);
    const float y = std::stof(match[3]);
    const auto &pair = toDraw.find(id);

    if (x < -0.1 || x > 1.1 || y < -0.1 || y > 1.1)
        return;
    if (pair == toDraw.end() || gameSprite.getType(match[1]) != pair->second.first)
        toDraw[id] = std::make_pair(gameSprite.getType(typeStr), gameSprite.getSpriteOfType(typeStr));
    toDraw.at(id).second.setPosition(x * window.getSize().x, y * window.getSize().y);
    std::cout << toDraw.at(id).second.getPosition().x << ',' << toDraw.at(id).second.getPosition().y << std::endl;
}

void updateWindow(sf::RenderWindow &window,
                  const std::unordered_map<int, std::pair<game::GameSprite::Type, sf::Sprite>> &toDraw)
{
    window.clear();
    if (!toDraw.empty()) {
        for (const auto &sprite : toDraw)
            window.draw(sprite.second.second);
        window.display();
    }
}

void endGame(game::INetwork *network)
{
    network->disconnect();
    delete network;
    std::cout << "client closed" << std::endl;
}

int display(game::INetwork *network)
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "r_type");
    game::GameSprite gameSprite;
    std::unordered_map<int, std::pair<game::GameSprite::Type, sf::Sprite>> toDraw;
    game::Buffer data;
    std::clock_t lastDrawTime = (double)std::clock() / CLOCKS_PER_SEC;

    window.display();
    while (window.isOpen()) {
        handle_events(network, window);
        std::size_t received = 0;
        if (network->receive(&data, sizeof(data), received))
            handleServerInstructions(gameSprite, window, data, toDraw);
        if ((double)std::clock() / CLOCKS_PER_SEC - lastDrawTime >= 0.016) {
            updateWindow(window, toDraw);
            lastDrawTime = (double)std::clock() / CLOCKS_PER_SEC;
        }
    }
    endGame(network);
    return 0;
}

int main()
{
    game::INetwork *network = new game::sfNetwork();
    if (!network->connect("127.0.0.1", 1234)) {
        std::cerr << "failed to connect" << std::endl;
        return 84;
    }
    std::cout << "connected !" << std::endl;
    return display(network);
}
