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

const std::vector<std::pair<std::string, ecs::DirectionComponent::Direction>> ecs::InputSystem::directions = {
    {"left", ecs::DirectionComponent::LEFT},
    {"right", ecs::DirectionComponent::RIGHT},
    {"up", ecs::DirectionComponent::UP},
    {"down", ecs::DirectionComponent::DOWN}
};
const std::string ecs::InputSystem::space = "space";

void ecs::InputSystem::update(float deltaTime)
{
    auto &connPool = GetPool<ConnectionComponent>(admin);
    auto &dirPool = GetPool<DirectionComponent>(admin);

    for (auto &c : GetPool<InputTuple>(admin)) {
        auto &conn = connPool.at(c.connectionIdx);
        auto &dir = dirPool.at(c.directionIdx);
        auto &buffers = conn.readBuffers;

        while (!buffers.empty()) {
            handleInput(c, buffers);
            buffers.pop();
        }
    }
}

void ecs::InputSystem::handleInput(const ecs::InputTuple &c, std::queue<std::array<char, 1024>> &buffers)
{
    for (auto &dir : directions) {
        auto str = dir.first;
        auto dirComp = dir.second;
        if (std::equal(str.begin(), str.end(), buffers.front().begin()))
            GetPool<DirectionComponent>(admin).at(c.directionIdx).setDirection(dirComp);
    }
    if (std::equal(space.begin(), space.end(), buffers.front().begin())) {
        auto &transform = GetPool<TransformComponent>(admin).at(c.transformIdx);
        float xCp = transform.vec.x;
        float yCp = transform.vec.y;

        EntityFactory::createBullet(admin, c.connectionIdx, GetPool<TransformComponent>(admin).create(xCp, yCp));
    }
}
