/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** main.cpp
*/

#include <thread>
#include "DispatchPacketSystem.hpp"
#include "EntityAdmin.hpp"
#include "SystemUtil.hpp"
#include "ReceiveSystem.hpp"
#include "ObjectPool.hpp"
#include "LobbyCommunication.hpp"

using namespace ecs;

int main()
{
    auto admin = std::make_shared<EntityAdmin>();
    ReceiveSystem receiveSystem(admin);
    DispatchPacketSystem dispatchPacketSystem(admin);
    auto systems = SystemsUtil::Init(admin);

    std::cout << "server listening on port " << admin->network.socket.local_endpoint().port() << std::endl;
    std::thread t([&receiveSystem]() {receiveSystem.update(0.16);});
    std::thread t2([&dispatchPacketSystem]() {
        while (true)
            dispatchPacketSystem.update(0.16);
    });

    LobbyCommunication::waitForStartGame(admin);
    LobbyCommunication::notifyPlayers(admin);
    LobbyCommunication::startGame(admin, systems);
    t.join();
    std::cout << "end" << std::endl;
}
