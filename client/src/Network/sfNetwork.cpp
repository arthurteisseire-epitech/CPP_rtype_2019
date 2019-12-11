/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include <iostream>
#include "sfNetwork.hpp"
#include "Buffer.hpp"

bool game::sfNetwork::connect(const std::string &IP, const unsigned &port)
{
    _IP = IP;
    _port = port;
    std::size_t a;
    if (socket.bind(sf::Socket::AnyPort) != sf::Socket::Done) {
        std::cerr << "failed to bind socket" << std::endl;
        return false;
    }
    game::Buffer conn(0, "connect");
    if (!send(&conn, sizeof(conn), a))
        std::cerr << "could not send connect" << std::endl;
    game::Buffer data;
    std::size_t received;
    if (socket.receive(&data, sizeof(data), received, _IP, _port) != sf::Socket::Done) {
        std::cerr << "did not receive" << std::endl;
        return false;
    }
    if (data.data != std::array<unsigned char, 256>{'o', 'k', 0}) {
        std::cerr << "received: \"" << data.data.data() << "\" instead of \"ok\"" << std::endl;
        return false;
    }
    socket.setBlocking(false);
    return true;
}

void game::sfNetwork::disconnect()
{
    _IP = "";
    _port = 0;
}

bool game::sfNetwork::send(const void *data, const size_t &size, std::size_t &)
{
    sf::IpAddress ip = _IP;
    unsigned short port = _port;
    const auto result = socket.send(data, size, ip, port);

    if (result != sf::Socket::Status::Done) {
        std::cerr << "send failed: socket status: ";
        switch (result) {
        case sf::Socket::Status::Error:
            std::cerr << "error" << std::endl;
            break;
        case sf::Socket::Status::Partial:
            std::cerr << "partial" << std::endl;
            break;
        case sf::Socket::Status::Disconnected:
            std::cerr << "disconnected" << std::endl;
            break;
        default:
            std::cerr << "unknown" << std::endl;
        }
        return false;
    }
    return true;
}

bool game::sfNetwork::receive(void *data, const std::size_t &size, std::size_t &received)
{
    sf::IpAddress ip = _IP;
    unsigned short port = _port;
    return socket.receive(data, size, received, ip, port) != sf::Socket::NotReady;
}
