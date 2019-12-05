/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ConnectionSystem.hpp
*/

#ifndef RTYPE_CONNECTIONSYSTEM_HPP
#define RTYPE_CONNECTIONSYSTEM_HPP

#include "ASystem.hpp"

namespace ecs
{
    class ConnectionSystem : public ASystem {
    public:
        explicit ConnectionSystem(std::shared_ptr<EntityAdmin> admin);

        void update(float) override;
    };
}

#endif
