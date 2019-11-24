/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** InputSystem.cpp
*/

#include "Util.hpp"
#include "InputTuple.hpp"
#include "InputSystem.hpp"

ecs::InputSystem::InputSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(std::move(admin))
{
}

void ecs::InputSystem::update(float deltaTime)
{
    std::vector<std::pair<std::string, DirectionComponent::Direction>> v = {
        {"left", DirectionComponent::LEFT},
        {"right", DirectionComponent::RIGHT},
        {"up", DirectionComponent::UP},
        {"down", DirectionComponent::DOWN}
    };

    for (auto &c : GetPool<InputTuple>(admin)) {
        auto &buffers = c.connectionComponent->readBuffers;
        while (!buffers.empty()) {
            for (auto &e : v) {
                auto s = e.first;
                auto key = e.second;
                if (std::equal(s.begin(), s.end(), buffers.front().begin())) {
                    c.directionComponent->setDirection(key);
                    std::cout << s << std::endl;
                }
            }
            buffers.pop();
        }
    }
}
