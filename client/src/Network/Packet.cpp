/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Vleb
*/

#include <cstring>
#include "Packet.hpp"

Client::Packet::Packet(const uint32_t &id) : _packet(new Client::RawPacket)
{
    _packet->magic = MAGIC_NB;
    _packet->payload.fill(0);
    _packet->id = id;
}

Client::Packet::Packet(const std::string &payload, const uint32_t &id) : _packet(new Client::RawPacket)
{
    _packet->magic = MAGIC_NB;
    _packet->payload.fill(0);
    this->setPayload(payload);
    _packet->id = id;
}

Client::Packet::Packet(const RawPacket &rawPacket) : _packet(new Client::RawPacket)
{
    memcpy(_packet, &rawPacket, sizeof(Client::RawPacket));
}

Client::Packet::~Packet()
{
    delete _packet;
}

Client::RawPacket *Client::Packet::getRaw() const
{
    return _packet;
}

std::array<uint8_t, 256> &Client::Packet::getPayload() const
{
    return _packet->payload;
}

uint32_t Client::Packet::getId() const
{
    return _packet->id;
}

void Client::Packet::setPayload(const std::string &s)
{
    std::copy(s.begin(), s.end(), _packet->payload.begin());
}
