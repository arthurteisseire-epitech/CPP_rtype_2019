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
    static auto nextId(std::shared_ptr<EntityAdmin> &admin)
    {
        return ++admin->current_id;
    }
}

#endif
