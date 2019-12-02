/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** InputDirectionSystem.hpp
*/

#ifndef RTYPE_INPUTDIRECTIONSYSTEM_HPP
#define RTYPE_INPUTDIRECTIONSYSTEM_HPP

#include "ASystem.hpp"

namespace ecs
{
    class InputDirectionSystem : public ASystem {
    public:
        explicit InputDirectionSystem(std::shared_ptr<EntityAdmin> admin);

        void update(float dt) override;

    private:
        static bool isKeyADirection(CInput::Key key);
        static const std::map<ecs::CInput::Key, ecs::CDirection::Direction> directions;
    };
}

#endif
