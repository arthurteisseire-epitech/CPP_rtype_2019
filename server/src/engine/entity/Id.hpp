/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ID.hpp
*/

#ifndef RTYPE_ID_HPP
#define RTYPE_ID_HPP

namespace ecs
{
    static int nextId()
    {
        static int id = 0;
        return ++id;
    }
}

#endif
