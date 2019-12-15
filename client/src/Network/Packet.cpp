/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Vleb
*/

#include <sstream>
#include "Packet.hpp"

Client::Packet::Packet(const uint32_t &id) :
    _packet(new Client::RawPacket), _destroy(true)
{
    _packet->magic = MAGIC_NB;
    _packet->payload.fill(0);
    _packet->id = id;
}

Client::Packet::Packet(const std::string &payload, const uint32_t &id) :
    _packet(new Client::RawPacket), _destroy(true)
{
    _packet->magic = MAGIC_NB;
    this->setPayload(payload);
    _packet->id = id;
}

Client::Packet::Packet(Client::RawPacket *rawPacket) :
    _packet(rawPacket), _destroy(true)
{
}

Client::Packet::Packet(Client::Packet &packet) :
    _packet(packet.getRaw()), _destroy(true)
{
    packet.disableDestruction();
}

Client::Packet::~Packet()
{
    if (_destroy) {
        delete _packet;
    }
}

Client::RawPacket *Client::Packet::getRaw() const
{
    return _packet;
}

std::string Client::Packet::getPayload() const
{
    return std::string(reinterpret_cast<char *>(_packet->payload.data()));
}

std::vector<std::string> Client::Packet::getParsedPayload() const
{
    std::istringstream splitStream(this->getPayload());
    std::string subPayload;
    std::vector<std::string> splitPayload;
    while (std::getline(splitStream, subPayload, ':')) {
        splitPayload.emplace_back(subPayload.c_str());
    }
    return splitPayload;
}

std::string Client::Packet::getPrefix() const
{
    return this->getParsedPayload()[0];
}

uint32_t Client::Packet::getId() const
{
    return _packet->id;
}

void Client::Packet::setPayload(const std::string &payload)
{
    _packet->payload.fill(0);
    std::copy(payload.begin(), payload.end(), _packet->payload.begin());
}

void Client::Packet::disableDestruction()
{
    _destroy = false;
}
