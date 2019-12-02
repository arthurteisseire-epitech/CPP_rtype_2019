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

        auto it = std::find_if(inputs.begin(), inputs.end(), &isKeyADirection);
        if (it != inputs.end()) {
            get<CDirection>(t).setDirection(directions.at(*it));
            inputs.erase(std::remove_if(inputs.begin(), inputs.end(), &isKeyADirection), inputs.end());
        } else {
            get<CDirection>(t).setDirection(CDirection::NONE);
        }
    });
}

bool ecs::InputDirectionSystem::isKeyADirection(ecs::CInput::Key key)
{
    return directions.find(key) != directions.end();
}
