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
    ForEachMatching<SendRenderTuple>(admin,
        [&buffer, this]
            (SendRenderTuple &tuple,
             ConnectionComponent &conn, TransformComponent &transform, TypeComponent &type, IdComponent &id) {

            auto s = std::to_string(id.id) + ";" + type.name + ":" + std::to_string(transform.vec.x) + "," +
                std::to_string(transform.vec.y) + '\n';
            buffer.fill(0);
            std::copy(s.begin(), s.end(), buffer.begin());
            NetworkUtil::send(admin, GetIndex<ConnectionComponent>(tuple), buffer);
        });
}
