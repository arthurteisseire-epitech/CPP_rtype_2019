/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_AMONSTER_HPP
#define RTYPE_AMONSTER_HPP

#include <memory>
#include "EntityAdmin.hpp"

namespace ecs
{
    class AMonster {
    public:
        virtual void update(std::shared_ptr<EntityAdmin> admin, float deltaTime) = 0;
    };
}

#endif
