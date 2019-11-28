/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_MOVESYSTEM_HPP
#define RTYPE_MOVESYSTEM_HPP

#include "ASystem.hpp"

namespace ecs
{
    class MoveSystem : public ASystem {
    public:
        explicit MoveSystem(std::shared_ptr<EntityAdmin> admin);

        void update(float dt) override;
    };
}

#endif
