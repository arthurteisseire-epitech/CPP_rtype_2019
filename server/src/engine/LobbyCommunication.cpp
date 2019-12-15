/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** LobbyCommunication.cpp
*/

#include "LobbyCommunication.hpp"
#include "EntityFactory.hpp"
#include "SendProtocol.hpp"
#include "NetworkSender.hpp"

void ecs::LobbyCommunication::waitStartGame(std::shared_ptr<EntityAdmin> &admin)
{
    bool gameStart = false;

    while (!gameStart) {
        ForEachMatching<CConnection>(admin, [&admin, &gameStart](CConnection &conn) {
            while (!conn.readBuffers.empty()) {
                auto &buffer = conn.readBuffers.front().data;
                std::string s(buffer.begin(), buffer.end());
                s.erase(std::remove_if(s.begin(), s.end(), iscntrl), s.end());

                if (ReceiveProtocol::find(s).first == ReceiveProtocol::GAME_REQUEST) {
                    conn.isInLobby = true;
                    notifyThisConnection(admin, conn, SendProtocol::MATE_CONNECTED);
                    notifyAllMates(admin, conn, SendProtocol::MATE_CONNECTED);
                }

                if (ReceiveProtocol::find(s).first == ReceiveProtocol::GAME_START)
                    gameStart = true;

                conn.readBuffers.pop();
            }
        });
    }
}

void ecs::LobbyCommunication::notifyPlayers(std::shared_ptr<EntityAdmin> &admin)
{
    for (std::size_t i = 0; i < GetPool<CConnection>(admin).size(); ++i)
        if (GetPool<CConnection>(admin).at(ObjectPool<CConnection>::index(i)).isInLobby)
            EntityFactory::createPlayer(admin, ObjectPool<CConnection>::index(i));

    ForEachMatching<NotifyPlayerTuple>(admin, [&admin](NotifyPlayerTuple &t) {
        auto s = SendProtocol::entitySetToString(GetFromTuple<CType>(t, admin).name,
                                                 GetFromTuple<CTransform>(t, admin).vec.x,
                                                 GetFromTuple<CTransform>(t, admin).vec.y) + ":player";

        NetworkSender::send(admin, GetFromTuple<CConnection>(t, admin), Packet(GetFromTuple<CId>(t, admin).id, s));
    });
}

void ecs::LobbyCommunication::startGame(std::shared_ptr<EntityAdmin> &admin,
                                        std::vector<std::unique_ptr<ASystem>> &systems)
{
    while (true) {
        SystemsUtil::Update(systems, 0.16);
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
    }
}

void ecs::LobbyCommunication::notifyThisConnection(std::shared_ptr<EntityAdmin> &admin, const CConnection &conn,
                                                   SendProtocol::Key messageKey)
{
    ForEachMatching<CConnection>(admin, [&admin, &conn, &messageKey](CConnection &mate) {
        if (mate.endpoint != conn.endpoint && mate.isInLobby)
            NetworkSender::send(admin, conn, Packet(0, SendProtocol::get(messageKey)));
    });
}

void ecs::LobbyCommunication::notifyAllMates(std::shared_ptr<EntityAdmin> &admin, const CConnection &conn,
                                             SendProtocol::Key messageKey)
{
    ForEachMatching<CConnection>(admin, [&admin, &conn, &messageKey](CConnection &mate) {
        if (mate.endpoint != conn.endpoint && mate.isInLobby)
            NetworkSender::send(admin, mate, Packet(0, SendProtocol::get(messageKey)));
    });
}
