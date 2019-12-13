/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SystemUtil.cpp
*/

#include "SystemUtil.hpp"
#include "CommandSystem.hpp"
#include "SendSystem.hpp"
#include "MoveSystem.hpp"
#include "UpdateTypeSystem.hpp"
#include "CreationBulletSystem.hpp"
#include "MonsterSpawningSystem.hpp"
#include "DispatchPacketSystem.hpp"
#include "CommandDirectionSystem.hpp"
#include "HandleConnectionSystem.hpp"
#include "ShootingAISystem.hpp"
#include "CollisionSystem.hpp"
#include "DestroyOOBSystem.hpp"

std::vector<std::unique_ptr<ecs::ASystem>> ecs::SystemsUtil::Init(std::shared_ptr<EntityAdmin> &admin)
{
    std::unique_ptr<ASystem> init[] = {
        std::make_unique<CreationBulletSystem>(admin),
        std::make_unique<DispatchPacketSystem>(admin),
        std::make_unique<CommandSystem>(admin),
        std::make_unique<HandleConnectionSystem>(admin),
        std::make_unique<UpdateTypeSystem>(admin),
        std::make_unique<MonsterSpawningSystem>(admin),
        std::make_unique<CommandDirectionSystem>(admin),
        std::make_unique<ShootingAISystem>(admin),
        std::make_unique<MoveSystem>(admin),
        std::make_unique<CollisionSystem>(admin),
        std::make_unique<DestroyOOBSystem>(admin),
        std::make_unique<SendSystem>(admin)
    };
    return std::vector<std::unique_ptr<ecs::ASystem>>{
        std::make_move_iterator(std::begin(init)),
        std::make_move_iterator(std::end(init))
    };
}

void ecs::SystemsUtil::Update(std::vector<std::unique_ptr<ecs::ASystem>> &systems, float deltaTime)
{
    for (auto &s : systems)
        s->update(deltaTime);
}
