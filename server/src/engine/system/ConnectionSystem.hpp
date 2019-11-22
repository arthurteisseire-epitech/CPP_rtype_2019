/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ConnectionSystem.hpp
*/

#ifndef RTYPE_CONNECTIONSYSTEM_HPP
#define RTYPE_CONNECTIONSYSTEM_HPP

#include "EntityAdmin.hpp"

namespace ecs
{
    class ConnectionSystem {
    public:
        static void update(float deltaTime, EntityAdmin &admin);
    };
}

#endif
