/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** main.cpp
*/

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <cstring>

static sf::TcpSocket *connect()
{
    auto socket = new sf::TcpSocket;
    sf::Socket::Status status = socket->connect("127.0.0.1", 1234);

    if (status != sf::Socket::Done)
        return nullptr;
    return socket;
}

int display(sf::TcpSocket *socket)
{
    auto s = new sf::String("toto");
    sf::RenderWindow window(sf::VideoMode(200, 200), *s);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    std::size_t sent;
    std::vector<std::pair<sf::Keyboard::Key, std::string>> keys = {
        {sf::Keyboard::Left, "left"},
        {sf::Keyboard::Right, "right"},
        {sf::Keyboard::Up, "up"},
        {sf::Keyboard::Down, "down"}
    };
    char data[1024] = {0};

    while (window.isOpen()) {

        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                for (auto &key : keys) {
                    if (sf::Keyboard::isKeyPressed(key.first)) {
                        socket->send(key.second.c_str(), key.second.length(), sent);
                        memset(data, 0, sizeof(char));

                        std::size_t received = 0;
                        socket->receive(&data, sizeof(data), received);
                        std::cout << data << std::endl;
                    }
                }
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    //    delete socket;
    return 0;
}

int main()
{
    auto socket = connect();
    if (socket == nullptr) {
        std::cout << "error connect" << std::endl;
        return 84;
    }
    return display(socket);
}
