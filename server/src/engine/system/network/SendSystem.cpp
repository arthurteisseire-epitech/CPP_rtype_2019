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
    ForEachMatching<SendRenderTuple>(admin, boost::bind(&ecs::SendSystem::updateTuple, this, _1, _2, _3, _4, _5));
}

void ecs::SendSystem::updateTuple(ecs::SendRenderTuple &tuple,
                                  ecs::ConnectionComponent &conn,
                                  ecs::TransformComponent &transform,
                                  ecs::TypeComponent &type,
                                  ecs::IdComponent &id)
{
    std::array<char, 1024> buffer{};

    auto s = std::to_string(id.id) + ";" + type.name + ":" + std::to_string(transform.vec.x) + "," +
        std::to_string(transform.vec.y) + '\n';
    buffer.fill(0);
    std::copy(s.begin(), s.end(), buffer.begin());
    NetworkUtil::send(admin, GetIndex<ConnectionComponent>(tuple), buffer);
}
