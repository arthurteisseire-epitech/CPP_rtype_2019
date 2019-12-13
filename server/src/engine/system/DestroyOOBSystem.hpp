/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** DestroyOobSystem.hpp
*/

#ifndef RTYPE_DESTROYOOBSYSTEM_HPP
#define RTYPE_DESTROYOOBSYSTEM_HPP

#include "ASystem.hpp"

namespace ecs
{
    class DestroyOOBSystem : public ASystem {
    public:
        explicit DestroyOOBSystem(std::shared_ptr<EntityAdmin> admin);

        void update(float) override;
    };
}

#endif
