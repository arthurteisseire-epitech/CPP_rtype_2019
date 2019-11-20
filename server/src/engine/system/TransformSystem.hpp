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
        explicit TransformSystem(std::shared_ptr<EntityAdmin> admin);
        void update(float dt);
    private:
        std::shared_ptr<EntityAdmin> admin;
    };
}

#endif
