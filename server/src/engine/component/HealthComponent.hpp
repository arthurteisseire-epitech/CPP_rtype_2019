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
    struct HealthComponent : public IComponent {
        int life = 100;
    };
}

#endif
