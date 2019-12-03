/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Vleb
*/

#include <cstring>
#include "Packet.hpp"

Client::Packet::Packet(const void *addr, const uint32_t &size) : _packet(new struct RawPacket)
{
    _packet->magic = 9360624;
    memset(_packet->payload, 0, 256);
    if (addr) {
        this->setPayload(addr, size);
    }
}

Client::Packet::~Packet()
{
    delete _packet;
}

Client::RawPacket *Client::Packet::getRaw() const
{
    return _packet;
}

uint8_t *Client::Packet::getPayload() const
{
    return _packet->payload;
}

void Client::Packet::setPayload(const void *addr, const uint32_t &size)
{
    memcpy(_packet->payload, addr, size);
}