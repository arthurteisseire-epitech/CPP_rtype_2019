/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios, modified by Vleb
*/

#include <stdexcept>
#include "Network.hpp"

Client::Network::Network(const std::string &ip, const uint16_t &port) :
    _socket(), _ip(ip), _port(port)
{
    _socket.setBlocking(false);
}

Client::Network::~Network()
{
    this->send("disconnect", 10);
}

void Client::Network::send(const void *data, const size_t &size)
{
    if (_socket.send(data, size, _ip, _port) != sf::Socket::Done)
        throw std::runtime_error("Socket is busy");
}

std::pair<std::string, uint16_t> Client::Network::receive(void *data, const std::size_t &size, std::size_t &received)
{
    sf::IpAddress connectionAddr;
    uint16_t connectionPort;
    if (_socket.receive(data, size, received, connectionAddr, connectionPort) != sf::Socket::Done)
        throw std::runtime_error("Socket is busy");
    return std::pair<std::string, uint16_t>(connectionAddr.toString(), connectionPort);
}
