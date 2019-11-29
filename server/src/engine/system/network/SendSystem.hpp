/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SendSystem.hpp
*/

#ifndef RTYPE_SENDSYSTEM_HPP
#define RTYPE_SENDSYSTEM_HPP

#include "ASystem.hpp"

namespace ecs
{
    class SendSystem : public ASystem {
    public:
        explicit SendSystem(std::shared_ptr<EntityAdmin> admin);

        void update(float deltaTime) override;
        void updateTuple(SendRenderTuple &t);
    };
}

#endif
