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
#include "LobbyCommunication.hpp"

using namespace ecs;

static void newGame()
{
    auto admin = std::make_shared<EntityAdmin>();
    auto systems = SystemsUtil::Init(admin);

    ReceiveSystem receiveSystem(admin);
    DispatchPacketSystem dispatchPacketSystem(admin);

    std::thread t1([&receiveSystem]() {receiveSystem.update(0.16);});
    std::thread t2([&dispatchPacketSystem]() {dispatchPacketSystem.update(0.16);});

    LobbyCommunication::waitForStartGame(admin);
    LobbyCommunication::notifyPlayers(admin);
    LobbyCommunication::startGame(admin, systems);
}

int main()
{
    newGame();
}
