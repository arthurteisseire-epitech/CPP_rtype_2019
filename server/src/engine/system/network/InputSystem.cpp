/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** InputSystem.cpp
*/

#include <NetworkUtil.hpp>
#include <EntityFactory.hpp>
#include "Util.hpp"
#include "InputTuple.hpp"
#include "InputSystem.hpp"

ecs::InputSystem::InputSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(std::move(admin))
{
}

const std::vector<std::pair<std::string, ecs::CDirection::Direction>> ecs::InputSystem::directions = {
    {"left", ecs::CDirection::LEFT},
    {"right", ecs::CDirection::RIGHT},
    {"up", ecs::CDirection::UP},
    {"down", ecs::CDirection::DOWN}
};
const std::string ecs::InputSystem::space = "space";

void ecs::InputSystem::update(float deltaTime)
{
    ForEachMatching<InputTuple>(admin,
        [this](InputTuple &t) {
            auto &buffers = get<CConnection>(t).readBuffers;

            while (!buffers.empty()) {
                handleInput(t);
                buffers.pop();
            }
        });
}

void ecs::InputSystem::handleInput(const ecs::InputTuple &t)
{
    for (auto &direction : directions) {
        auto str = direction.first;
        auto dirComp = direction.second;
        if (std::equal(str.begin(), str.end(), get<CConnection>(t).readBuffers.front().begin()))
            get<CDirection>(t).setDirection(dirComp);
    }
    if (std::equal(space.begin(), space.end(), get<CConnection>(t).readBuffers.front().begin())) {
        float xCp = get<CTransform>(t).vec.x;
        float yCp = get<CTransform>(t).vec.y;

        EntityFactory::createBullet(admin, GetIndex<CConnection>(t),
            GetPool<CTransform>(admin).create(xCp, yCp));
    }
}
