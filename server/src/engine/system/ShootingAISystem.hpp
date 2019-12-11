/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_SHOOTINGAISYSTEM_HPP
#define RTYPE_SHOOTINGAISYSTEM_HPP

#include "ASystem.hpp"

namespace ecs
{
    class ShootingAISystem : public ASystem {
    public:
        explicit ShootingAISystem(std::shared_ptr<EntityAdmin> admin);
        void update(float dtime) override;
    };
}

#endif
