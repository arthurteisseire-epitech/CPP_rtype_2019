/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_MONSTERSPAWNINGSYSTEM_HPP
#define RTYPE_MONSTERSPAWNINGSYSTEM_HPP

#include "ASystem.hpp"
#include "Vector2.hpp"

namespace ecs
{
    class MonsterSpawningSystem : public ASystem {
    public:
        explicit MonsterSpawningSystem(std::shared_ptr<EntityAdmin> admin);
        void update(float dtime) override;

    private:
        static mut::Vec2f generateRandomPosition();
    };
}

#endif
