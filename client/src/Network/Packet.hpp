/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Vleb
*/

#ifndef RTYPE_PACKET_HPP
#define RTYPE_PACKET_HPP

//SEND
#define PACKET_ACTION_UP "action_up"
#define PACKET_ACTION_DOWN "action_down"
#define PACKET_ACTION_LEFT "action_left"
#define PACKET_ACTION_RIGHT "action_right"
#define PACKET_ACTION_SPACE "action_space"
#define PACKET_CONNECT "connect"
#define PACKET_DISCONNECT "disconnect"
#define PACKET_ENTITY_COLLISION "entity_collision"
#define PACKET_START_GAME "start_game"

//RECEIVE
#define PACKET_ENTITY_DELETE "entity_delete"
#define PACKET_ENTITY_SET "entity_set"
#define PACKET_MATE_CONNECTED "mate_connected"
#define PACKET_MATE_LOST "mate_lost"
#define PACKET_PLAYER_CONNECTED "player_connected"

#define MAGIC_NB 9360624
#define DEFAULT_ID 0

#include <cstdint>
#include <SFML/Network.hpp>
#include <string>
#include <vector>

namespace Client {
    struct RawPacket {
        uint32_t magic;
        std::array<uint8_t, 256> payload;
        uint32_t id;
    };

    class Packet {
    public:
        Packet(const uint32_t &id = DEFAULT_ID);
        Packet(const std::string &payload, const uint32_t &id = DEFAULT_ID);
        Packet(Client::RawPacket *rawPacket);
        Packet(Client::Packet &packet);
        ~Packet();
        RawPacket *getRaw() const;
        std::string getPayload() const;
        std::vector<std::string> getParsedPayload() const;
        std::string getPrefix() const;
        uint32_t getId() const;
        void setPayload(const std::string &payload);
        void disableDestruction();
    private:
        RawPacket *_packet;
        bool _destroy;
    };
}

#endif
