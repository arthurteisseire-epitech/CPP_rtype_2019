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
    auto &idPool = GetPool<IdComponent>(admin);
    auto &typePool = GetPool<TypeComponent>(admin);

    for (auto &t : GetPool<SendRenderTuple>(admin)) {
        auto &transform = transformPool.at(t.transformIdx);
        auto &id = idPool.at(t.idIdx);
        auto &type = typePool.at(t.typeIdx);
        auto s = std::to_string(id.id) + ";" + type.name + ":" + std::to_string(transform.vec.x) + "," + std::to_string(transform.vec.y) + '\n';
        buffer.fill(0);
        std::copy(s.begin(), s.end(), buffer.begin());
        NetworkUtil::send(admin, t.connectionIdx, buffer);
    }
}
