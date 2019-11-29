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
    ForEachMatching<InputTuple>(admin,
        [this](InputTuple &tuple, ConnectionComponent &conn, TransformComponent &transform, DirectionComponent &dir) {
            auto &buffers = conn.readBuffers;

            while (!buffers.empty()) {
                handleInput(tuple, conn, dir, transform);
                buffers.pop();
            }
        }
    );
}

void ecs::InputSystem::handleInput(InputTuple &tuple, ConnectionComponent &conn, DirectionComponent &dir,
                                   TransformComponent &transform)
{
    auto &buffers = conn.readBuffers;
    for (auto &direction : directions) {
        auto str = direction.first;
        auto dirComp = direction.second;
        if (std::equal(str.begin(), str.end(), buffers.front().begin()))
            dir.setDirection(dirComp);
    }
    if (std::equal(space.begin(), space.end(), buffers.front().begin())) {
        float xCp = transform.vec.x;
        float yCp = transform.vec.y;

        EntityFactory::createBullet(admin, GetIndex<ConnectionComponent>(tuple),
            GetPool<TransformComponent>(admin).create(xCp, yCp));
    }
}
