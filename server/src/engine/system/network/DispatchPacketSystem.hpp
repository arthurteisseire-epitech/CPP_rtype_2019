/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** DispatchPacketSystem.hpp
*/

#ifndef RTYPE_DISPATCHPACKETSYSTEM_HPP
#define RTYPE_DISPATCHPACKETSYSTEM_HPP

#include "ASystem.hpp"

namespace ecs
{
    class DispatchPacketSystem : public ASystem {
    public:
        explicit DispatchPacketSystem(std::shared_ptr<EntityAdmin> admin);

        void update(float) override;
    };
}

#endif
