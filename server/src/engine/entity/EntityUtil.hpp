/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** DestroyEntity.hpp
*/

#ifndef RTYPE_ENTITYUTIL_HPP
#define RTYPE_ENTITYUTIL_HPP

#include "EntityAdmin.hpp"

namespace ecs
{
    class EntityUtil {
    public:
        static void DestroyEntity(std::shared_ptr<EntityAdmin> &admin, unsigned int id);
    };
}

#endif
