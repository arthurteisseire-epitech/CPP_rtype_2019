/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** main.cpp
*/

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>

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
    sf::Packet packet;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    packet << "Left";
                    socket->send(packet);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    packet << "Right";
                    socket->send(packet);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    packet << "Up";
                    socket->send(packet);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    packet << "Down";
                    socket->send(packet);
                }
            }
            packet.clear();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

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
