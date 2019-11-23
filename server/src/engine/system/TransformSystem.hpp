/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** TransformSystem.hpp
*/

#ifndef RTYPE_TRANSFORMSYSTEM_HPP
#define RTYPE_TRANSFORMSYSTEM_HPP

#include <memory>
#include "EntityAdmin.hpp"
#include "ASystem.hpp"

namespace ecs
{
    class TransformSystem : public ASystem {
    public:
        explicit TransformSystem(std::shared_ptr<EntityAdmin> admin);

        void update(float dt);
    };
}

#endif
