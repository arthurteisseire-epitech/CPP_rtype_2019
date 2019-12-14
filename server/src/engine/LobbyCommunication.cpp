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

void ecs::LobbyCommunication::waitForStartGame(std::shared_ptr<EntityAdmin> &admin)
{
    auto &buffers = admin->network.readBuffers;
    bool gameStart = false;

    while (true) {
        ForEachMatching<CConnection>(admin, [&admin, &gameStart](CConnection &conn) {
            while (!conn.readBuffers.empty()) {
                auto &packet = conn.readBuffers.front();
                auto &buffer = packet.data;
                std::string s(buffer.begin(), buffer.end());
                s.erase(std::remove_if(s.begin(), s.end(), iscntrl), s.end());

                if (ReceiveProtocol::find(s).first == ReceiveProtocol::GAME_REQUEST)
                    notifyAllMates(admin, packet, conn.endpoint);

                if (ReceiveProtocol::find(s).first == ReceiveProtocol::GAME_START)
                    gameStart = true;

                conn.readBuffers.pop();
            }
        });
        if (gameStart)
            break;
    }
}

void ecs::LobbyCommunication::notifyPlayers(std::shared_ptr<EntityAdmin> &admin)
{
    for (std::size_t i = 0; i < GetPool<CConnection>(admin).size(); ++i)
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
        std::this_thread::sleep_for(std::chrono::milliseconds(160));
    }
}

void ecs::LobbyCommunication::notifyAllMates(std::shared_ptr<EntityAdmin> &admin, Packet &packet,
                                             const boost::asio::ip::udp::endpoint &endpoint)
{
    ForEachMatching<CConnection>(admin, [&admin, &packet, &endpoint](CConnection &conn) {
        if (endpoint == conn.endpoint) {
            for (std::size_t i = 0; i < GetPool<CConnection>(admin).size() - 1; ++i)
                NetworkSender::send(admin, conn, Packet(0, SendProtocol::get(SendProtocol::MATE_CONNECTED)));
        } else {
            NetworkSender::send(admin, conn, Packet(0, SendProtocol::get(SendProtocol::MATE_CONNECTED)));
        }
    });
}
