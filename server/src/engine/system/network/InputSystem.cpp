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
        [this](InputTuple &t) {
            auto &buffers = get<ConnectionComponent>(t).readBuffers;

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
        if (std::equal(str.begin(), str.end(), get<ConnectionComponent>(t).readBuffers.front().begin()))
            get<DirectionComponent>(t).setDirection(dirComp);
    }
    if (std::equal(space.begin(), space.end(), get<ConnectionComponent>(t).readBuffers.front().begin())) {
        float xCp = get<TransformComponent>(t).vec.x;
        float yCp = get<TransformComponent>(t).vec.y;

        EntityFactory::createBullet(admin, GetIndex<ConnectionComponent>(t),
            GetPool<TransformComponent>(admin).create(xCp, yCp));
    }
}
