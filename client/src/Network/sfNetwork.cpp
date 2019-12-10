/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include "sfNetwork.hpp"

bool game::sfNetwork::connect(const std::string &IP, const unsigned &port)
{
    _IP = IP;
    _port = port;
    std::size_t a;
    socket.setBlocking(false);
    send("connect", sizeof("connect"), a);
    return true;
}

void game::sfNetwork::disconnect()
{
    _IP = "";
    _port = 0;
}

#include "iostream"
void game::sfNetwork::send(const void *data, const size_t &size, std::size_t &)
{
    socket.send(data, size, _IP, _port);
}

bool game::sfNetwork::receive(void *data, const std::size_t &size, std::size_t &received)
{
    return socket.receive(data, size, received, _IP, _port) != sf::Socket::NotReady;
}
