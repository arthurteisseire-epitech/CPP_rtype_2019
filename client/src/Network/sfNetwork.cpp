/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include "sfNetwork.hpp"

bool game::sfNetwork::connect(const std::string &IP, const unsigned &port)
{
    sf::Socket::Status status = socket.connect(IP, port);

    if (status != sf::Socket::Done)
        return false;
    socket.setBlocking(false);
    return true;
}

void game::sfNetwork::disconnect()
{
    socket.disconnect();
}

void game::sfNetwork::send(const void *data, const size_t &size, std::size_t &sent)
{
    socket.send(data, size, sent);
}

bool game::sfNetwork::receive(void *data, const std::size_t &size, std::size_t &received)
{
    return socket.receive(data, size, received) != sf::Socket::NotReady;
}
