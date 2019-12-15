/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CHealth.hpp
*/

#ifndef RTYPE_CHEALTH_HPP
#define RTYPE_CHEALTH_HPP

namespace ecs
{
    struct CHealth {
        CHealth(int life = 100) :
            life(life),
            maxLife(life)
        {
        }

        [[nodiscard]] float getLifeRatio() const
        {
            return static_cast<float>(life) / static_cast<float>(maxLife);
        }

        int life;
        int maxLife;
    };
}

#endif
