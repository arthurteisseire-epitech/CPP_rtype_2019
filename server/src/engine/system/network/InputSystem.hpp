/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** InputSystem.hpp
*/

#ifndef RTYPE_INPUTSYSTEM_HPP
#define RTYPE_INPUTSYSTEM_HPP

#include "ASystem.hpp"

namespace ecs
{
    class InputSystem : public ASystem {
    public:
        explicit InputSystem(std::shared_ptr<EntityAdmin> admin);
        void update(float deltaTime) override;

    private:
        static const std::unordered_map<std::string, CDirection::Direction> directions;
        static const std::string space;
        static const std::unordered_map<std::string, std::function<void((ecs::InputSystem &, ecs::InputTuple &))>> inputMap;

        void handleInput(InputTuple &t);
    };
}

#endif
