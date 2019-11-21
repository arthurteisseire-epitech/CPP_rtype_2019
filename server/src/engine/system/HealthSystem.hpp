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
        static void update(float dt, EntityAdmin &admin);
    };
}

#endif
