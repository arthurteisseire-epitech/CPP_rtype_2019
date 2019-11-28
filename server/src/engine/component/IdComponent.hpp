/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_IDCOMPONENT_HPP
#define RTYPE_IDCOMPONENT_HPP

namespace ecs
{
    struct IdComponent {
        IdComponent(int id) : id(id) {}
        int id;
    };
}

#endif
