/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios, modified by Vleb
*/

#ifndef RTYPE_NETWORK_HPP
#define RTYPE_NETWORK_HPP

#include <SFML/Network.hpp>
#include <vector>
#include "INetwork.hpp"
#include "Packet.hpp"

namespace Client {
    class Network : public INetwork {
    public:
        Network(const std::string &ip, const uint16_t &port);
        ~Network() override;
        void send(const void *data, const std::size_t &size) override;
        std::pair<std::string, uint16_t> receive(void *data, const std::size_t &size, std::size_t &received) override;
    private:
        sf::UdpSocket _socket;
        sf::IpAddress _ip;
        uint16_t _port;
        std::vector<Client::Packet> _buffer;
    };
}

#endif
