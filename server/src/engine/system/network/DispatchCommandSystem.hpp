/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** DispatchCommandSystem.hpp
*/

#ifndef RTYPE_DISPATCHCOMMANDSYSTEM_HPP
#define RTYPE_DISPATCHCOMMANDSYSTEM_HPP

#include "ASystem.hpp"

namespace ecs
{
    class DispatchCommandSystem : public ASystem {
    public:
        explicit DispatchCommandSystem(std::shared_ptr<EntityAdmin> admin);

        void update(float) override;
    };
}

#endif
