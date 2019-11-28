/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** InputSystem.cpp
*/

#include <NetworkUtil.hpp>
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
    auto &connPool = GetPool<ConnectionComponent>(admin);
    auto &dirPool = GetPool<DirectionComponent>(admin);

    for (auto &c : GetPool<InputTuple>(admin)) {
        auto &conn = connPool.at(c.connectionIdx);
        auto &dir = dirPool.at(c.directionIdx);
        auto &buffers = conn.readBuffers;

        while (!buffers.empty()) {
            for (auto &e : v) {
                auto s = e.first;
                auto key = e.second;
                if (std::equal(s.begin(), s.end(), buffers.front().begin())) {
                    dir.setDirection(key);
                    NetworkUtil::send(admin, c.connectionIdx, std::array<char, 1024>{"toto"});
                    std::cout << s << std::endl;
                }
            }
            buffers.pop();
        }
    }
}
