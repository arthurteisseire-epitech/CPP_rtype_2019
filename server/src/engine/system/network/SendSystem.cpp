/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SendSystem.cpp
*/

#include <boost/bind.hpp>
#include "SendSystem.hpp"
#include "Sender.hpp"
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

    auto s = std::to_string(get<CId>(t).id) + ';' + get<CType>(t).name + ':' + std::to_string(get<CTransform>(t).vec.x) + ',' +
        std::to_string(get<CTransform>(t).vec.y) + '\n';
    std::copy(s.begin(), s.end(), buffer.begin());
    new Sender(admin, GetIndex<CConnection>(t), buffer);
}
