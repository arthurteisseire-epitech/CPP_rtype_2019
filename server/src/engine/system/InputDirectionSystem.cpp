/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** InputDirectionSystem.cpp
*/

#include <utility>
#include "InputDirectionSystem.hpp"

const std::map<ecs::CInput::Key, ecs::CDirection::Direction> ecs::InputDirectionSystem::directions = {
    {ecs::CInput::LEFT, ecs::CDirection::LEFT},
    {ecs::CInput::RIGHT, ecs::CDirection::RIGHT},
    {ecs::CInput::UP, ecs::CDirection::UP},
    {ecs::CInput::DOWN, ecs::CDirection::DOWN}
};

ecs::InputDirectionSystem::InputDirectionSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(std::move(admin))
{
}

void ecs::InputDirectionSystem::update(float dt)
{
    ForEachMatching<InputDirectionTuple>(admin, [this] (InputDirectionTuple &t) {

        auto &inputs = get<CInput>(t).inputs;
        std::size_t i = updateDirection(t);

        if (i == inputs.size())
            get<CDirection>(t).setDirection(CDirection::NONE);

        inputs.erase(std::remove_if(inputs.begin(), inputs.end(), [] (CInput::Key key) {
            return directions.find(key) != directions.end();
        }), inputs.end());
    });
}

std::size_t ecs::InputDirectionSystem::updateDirection(ecs::InputDirectionTuple &t)
{
    auto &inputs = get<CInput>(t).inputs;
    std::size_t i;

    for (i = 0; i < inputs.size(); ++i) {
        for (auto p : ecs::InputDirectionSystem::directions) {
            if (inputs.at(i) == p.first) {
                get<CDirection>(t).setDirection(p.second);
                return i;
            }
        }
    }
    return i;
}
