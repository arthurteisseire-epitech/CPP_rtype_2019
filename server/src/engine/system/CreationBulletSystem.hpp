/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CreationBulletSystem.hpp
*/

#ifndef RTYPE_CREATIONBULLETSYSTEM_HPP
#define RTYPE_CREATIONBULLETSYSTEM_HPP

#include "ASystem.hpp"

namespace ecs
{
    class CreationBulletSystem : public ASystem {
    public:
        explicit CreationBulletSystem(std::shared_ptr<EntityAdmin> admin);
        void update(float deltaTime) override;
    };
}

#endif