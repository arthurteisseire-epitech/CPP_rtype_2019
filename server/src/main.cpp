/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** main.cpp
*/

#include "EntityAdmin.hpp"
#include "SystemUtil.hpp"

#include "ReceiveSystem.hpp"
#include "DynamicLoadMonsterSystem.hpp"
#include "DispatchPacketSystem.hpp"

#include "SystemThreadPool.hpp"
#include "LobbyCommunication.hpp"

using namespace ecs;

static void newGame()
{
    auto admin = std::make_shared<EntityAdmin>();
    auto systems = SystemsUtil::Init(admin);
    SystemThreadPool<ReceiveSystem, DispatchPacketSystem, DynamicLoadMonsterSystem> systemThreadPool(admin);

    LobbyCommunication::waitForStartGame(admin);
    LobbyCommunication::notifyPlayers(admin);
    LobbyCommunication::startGame(admin, systems);
}

int main()
{
    newGame();
}
