/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios, modified by Vleb
*/

#ifndef RTYPE_NETWORK_HPP
#define RTYPE_NETWORK_HPP

#include <SFML/Network.hpp>
#include <string>
#include <vector>
#include "Packet.hpp"

namespace Client {
    class Network {
    public:
        Network(const std::string &ip, const uint16_t &port);
        ~Network();
        void send(const void *data, const uint64_t &size);
        void send(const Client::RawPacket *packet);
        std::pair<std::string, uint16_t> receive(void *data, const uint64_t &size, uint64_t &received);
        Client::Packet findReceived(const uint32_t &id);
    private:
        void receiver();
        sf::UdpSocket _socket;
        sf::IpAddress _ip;
        uint16_t _port;
        bool _active;
        sf::Thread _receiver;
        std::vector<Client::RawPacket> _buffer;
        sf::Mutex _mutex;
    };
}

#endif
