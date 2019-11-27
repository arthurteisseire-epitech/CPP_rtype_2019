/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/


#ifndef RTYPE_SFNETWORK_HPP
#define RTYPE_SFNETWORK_HPP

#include <SFML/Network.hpp>
#include "INetwork.hpp"

namespace game
{
    class sfNetwork : public INetwork {
    public:
        bool connect(const std::string &IP, const unsigned &port) override;
        void disconnect() override;
        void send(const void *data, const size_t &size, std::size_t &sent) override;
        bool receive(void *data, const std::size_t &size, std::size_t &received) override;

    private:
        sf::TcpSocket socket;
    };
}

#endif
