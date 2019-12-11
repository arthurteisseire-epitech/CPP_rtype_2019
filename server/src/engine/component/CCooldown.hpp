/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_CCOOLDOWN_HPP
#define RTYPE_CCOOLDOWN_HPP

namespace ecs
{
    struct CCooldown {
        CCooldown(const float &total, const float &remaining = 0) : total(total), remaining(remaining) {}

        float total;
        float remaining;
    };
}

#endif
