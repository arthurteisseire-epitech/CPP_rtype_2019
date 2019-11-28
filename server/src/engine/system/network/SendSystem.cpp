/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SendSystem.cpp
*/

#include "SendSystem.hpp"
#include "NetworkUtil.hpp"
#include "Util.hpp"

ecs::SendSystem::SendSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(std::move(admin))
{
}

void ecs::SendSystem::update(float deltaTime)
{
    std::array<char, 1024> buffer{};
    auto &transformPool = GetPool<TransformComponent>(admin);

    for (auto &t : GetPool<SendTuple>(admin)) {
        auto &transform = transformPool.at(t.transformIdx);

        auto s = "x:" + std::to_string(transform.vec.x) + ",y:" + std::to_string(transform.vec.y) + '\n';
        buffer.fill(0);
        std::copy(s.begin(), s.end(), buffer.begin());

        NetworkUtil::send(admin, t.connectionIdx, buffer);
    }
}
