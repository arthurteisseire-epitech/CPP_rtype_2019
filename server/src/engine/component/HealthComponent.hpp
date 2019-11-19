/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** HealthComponent.hpp
*/

#ifndef RTYPE_HEALTHCOMPONENT_HPP
#define RTYPE_HEALTHCOMPONENT_HPP

namespace ecs
{
    struct HealthComponent {
        explicit HealthComponent(int life = 100) :
            life(life)
        {
        }

        int life;
    };
}

#endif
