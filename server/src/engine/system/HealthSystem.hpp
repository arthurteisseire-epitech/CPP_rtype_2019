/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** HealthSystem.hpp
*/

#ifndef RTYPE_HEALTHSYSTEM_HPP
#define RTYPE_HEALTHSYSTEM_HPP

#include <memory>
#include "EntityAdmin.hpp"

namespace ecs
{
    class HealthSystem {
    public:
        explicit HealthSystem(std::shared_ptr<EntityAdmin> admin);
        void update(float dt);
    private:
        std::shared_ptr<EntityAdmin> admin;
    };
}

#endif
