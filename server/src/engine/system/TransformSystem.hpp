/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** TransformSystem.hpp
*/

#ifndef RTYPE_TRANSFORMSYSTEM_HPP
#define RTYPE_TRANSFORMSYSTEM_HPP

#include "EntityAdmin.hpp"
#include <memory>

namespace ecs
{
    class TransformSystem {
    public:
        static void update(float dt, ecs::EntityAdmin &admin);
    };
}

#endif
