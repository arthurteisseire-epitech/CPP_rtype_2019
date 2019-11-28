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
    for (auto &c : GetPool<InputTuple>(admin)) {
        auto &buffers = c.connection->readBuffers;
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
            c.direction->setDirection(dirComp);
    }
    if (std::equal(space.begin(), space.end(), buffers.front().begin())) {
        float xCp = c.transform->vec.x;
        float yCp = c.transform->vec.y;
        EntityFactory::createBullet(admin, c.connection, GetPool<TransformComponent>(admin).create(xCp, yCp));
    }
}
