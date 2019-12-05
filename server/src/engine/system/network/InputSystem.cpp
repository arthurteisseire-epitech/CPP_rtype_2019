/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** InputSystem.cpp
*/

#include "InputSystem.hpp"
#include "CInput.hpp"
#include "InputTuple.hpp"

ecs::InputSystem::InputSystem(std::shared_ptr<EntityAdmin> admin) :
    ASystem(std::move(admin))
{
}

const std::map<std::string, ecs::CInput::Key> ecs::InputSystem::directions = {
    {"left", ecs::CInput::LEFT},
    {"right", ecs::CInput::RIGHT},
    {"up", ecs::CInput::UP},
    {"down", ecs::CInput::DOWN},
    {"space", ecs::CInput::SPACE},
};

void ecs::InputSystem::update(float deltaTime)
{
    ForEachMatching<InputTuple>(admin, [this](InputTuple &t) {

        auto &buffers = get<CConnection>(t).readBuffers;

        get<CInput>(t).inputs.clear();
        get<CInput>(t).inputs.reserve(buffers.size());
        while (!buffers.empty()) {
            std::string s(std::begin(buffers.front()), std::end(buffers.front()));
            s.erase(std::remove_if(s.begin(), s.end(), iscntrl), s.end());

            auto it = directions.find(s);
            if (it != directions.end())
                get<CInput>(t).inputs.push_back(it->second);
            buffers.pop();
        }
    });
}
