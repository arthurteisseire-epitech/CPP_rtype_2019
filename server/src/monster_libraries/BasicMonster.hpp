/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_BASICMONSTER_HPP
#define RTYPE_BASICMONSTER_HPP

#include "AMonster.hpp"

namespace ecs
{
    class BasicMonster : public AMonster {
    public:
        void update(std::shared_ptr<EntityAdmin> admin, float deltaTime);

    private:
        float remaining = 0;
        static mut::Vec2f generateRandomPosition();
    };
}

#endif
