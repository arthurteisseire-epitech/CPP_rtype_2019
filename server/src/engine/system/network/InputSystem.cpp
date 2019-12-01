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

const std::unordered_map<std::string, ecs::CDirection::Direction> ecs::InputSystem::directions = {
    {"left", ecs::CDirection::LEFT},
    {"right", ecs::CDirection::RIGHT},
    {"up", ecs::CDirection::UP},
    {"down", ecs::CDirection::DOWN}
};
const std::string ecs::InputSystem::space = "space";
const std::unordered_map<std::string, std::function<void(ecs::InputSystem &, ecs::InputTuple &)>> ecs::InputSystem::inputMap = {
    {"left", [] (InputSystem &sys, InputTuple &t) {
        sys.get<ecs::CDirection>(t).setDirection(CDirection::LEFT);
    }},
    {"right", [] (InputSystem &sys, InputTuple &t) {
        sys.get<ecs::CDirection>(t).setDirection(CDirection::RIGHT);
    }},
    {"up", [] (InputSystem &sys, InputTuple &t) {
        sys.get<ecs::CDirection>(t).setDirection(CDirection::UP);
    }},
    {"down", [] (InputSystem &sys, InputTuple &t) {
        sys.get<ecs::CDirection>(t).setDirection(CDirection::DOWN);
    }},
    {"space", [] (InputSystem &sys, InputTuple &t) {
        float xCp = sys.get<CTransform>(t).vec.x;
        float yCp = sys.get<CTransform>(t).vec.y;

        EntityFactory::createBullet(sys.admin, GetIndex<CConnection>(t),
            GetPool<CTransform>(sys.admin).create(xCp, yCp));
    }},
    {"r", [] (InputSystem &sys, InputTuple &t) {
        std::cout << "pressed r" << std::endl;
    }},
};

void ecs::InputSystem::update(float)
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

void ecs::InputSystem::handleInput(InputTuple &t)
{
    const std::string input = get<CConnection>(t).readBuffers.front().begin();
    const auto &inputHandler = inputMap.find(input);

    if (inputHandler != inputMap.end())
        inputHandler->second(*this, t);
    else
        std::cerr << "unknown command: " << input << std::endl;
}
