/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SendSystem.cpp
*/

#include <boost/bind.hpp>
#include "SendSystem.hpp"
#include "NetworkUtil.hpp"
#include "Util.hpp"

ecs::SendSystem::SendSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(std::move(admin))
{
}

void ecs::SendSystem::update(float deltaTime)
{
    ForEachMatching<SendRenderTuple>(admin, boost::bind(&ecs::SendSystem::updateTuple, this, _1));
}

void ecs::SendSystem::updateTuple(ecs::SendRenderTuple &t)
{
    std::array<char, 1024> buffer{};

    auto s = std::to_string(get<IdComponent>(t).id) + ";" + get<TypeComponent>(t).name + ":" + std::to_string(get<TransformComponent>(t).vec.x) + "," +
        std::to_string(get<TransformComponent>(t).vec.y) + '\n';
    buffer.fill(0);
    std::copy(s.begin(), s.end(), buffer.begin());
    NetworkUtil::send(admin, GetIndex<ConnectionComponent>(t), buffer);
}
