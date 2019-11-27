/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_SHOOTSYSTEM_HPP
#define RTYPE_SHOOTSYSTEM_HPP

#include "ASystem.hpp"

namespace ecs
{
    class ShootSystem : public ASystem {
    public:
        explicit ShootSystem(std::shared_ptr<EntityAdmin> admin);
        void update(float dt);
    };
}

#endif
