/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios, modified by Vleb
*/

#include <iostream>
#include "Network.hpp"

Client::Network::Network(const std::pair<std::string, uint16_t> &serverAddr, const uint16_t &clientPort) :
    _socket(), _serverIp(serverAddr.first), _serverPort(serverAddr.second), _active(true), _receiver(&Client::Network::receiver, this)
{
    _socket.bind(clientPort);
    this->send(Client::Packet(PACKET_CONNECT).getRaw());
    _receiver.launch();
}

Client::Network::~Network()
{
    _mutex.lock();
    _active = false;
    _mutex.unlock();
    this->send(Client::Packet(PACKET_DISCONNECT).getRaw());
    _receiver.terminate();
    _mutex.lock();
    for (auto &packet : _buffer) {
        delete packet;
    }
    _mutex.unlock();
}

void Client::Network::send(const void *data, const uint64_t &size)
{
    _socket.send(data, size, _serverIp, _serverPort);
}

void Client::Network::send(const Client::RawPacket *packet)
{
    this->send(packet, sizeof(Client::RawPacket));
    std::cout << "Sent: \'" << packet->payload.data() << "\' on ID: " << packet->id << std::endl;
}

std::pair<std::string, uint16_t> Client::Network::receive(void *data, const uint64_t &size, uint64_t &received)
{
    sf::IpAddress connectionAddr;
    uint16_t connectionPort;
    _socket.receive(data, size, received, connectionAddr, connectionPort);
    return std::pair<std::string, uint16_t>(connectionAddr.toString(), connectionPort);
}

Client::Packet Client::Network::findReceived(const uint64_t &index)
{
    if (index < _buffer.size()) {
        return Client::Packet(_buffer[index]);
    } else {
        throw std::runtime_error("\'Client::Network::findReceived\': No packet found.");
    }
}

Client::Packet Client::Network::findReceived(const uint32_t &id)
{
    for (uint64_t i = 0; i < _buffer.size(); i++) {
        if (_buffer[i]->id == id) {
            Client::Packet packet(_buffer[i]);
            this->removeFromBuffer(i);
            return packet;
        }
    }
    throw std::runtime_error("\'Client::Network::findReceived\': No packet found.");
}

Client::Packet Client::Network::findReceived(const std::string &prefix)
{
    for (uint64_t i = 0; i < _buffer.size(); i++) {
        Client::Packet packet(_buffer[i]);
        if (packet.getPrefix() == prefix) {
            this->removeFromBuffer(i);
            return packet;
        } else {
            packet.disableDestruction();
        }
    }
    throw std::runtime_error("\'Client::Network::findReceived\': Packet not found: " + prefix);
}

void Client::Network::removeFromBuffer(const uint64_t &index)
{
    _mutex.lock();
    _buffer.erase(_buffer.begin() + index);
    _mutex.unlock();
}

void Client::Network::emptyBuffer()
{
    _mutex.lock();
    for (auto &packet : _buffer) {
        delete packet;
    }
    _buffer.clear();
    _mutex.unlock();
}

void Client::Network::receiver()
{
    while (_active) {
        auto packet = new Client::RawPacket;
        uint64_t received = 0;
        do {
            this->receive(packet, sizeof(Client::RawPacket), received);
        } while (!received || packet->magic != MAGIC_NB);
        std::cout << "Received: \'" << packet->payload.data() << "\' on ID: " << packet->id << std::endl;
        _mutex.lock();
        _buffer.push_back(packet);
        _mutex.unlock();
    }
}