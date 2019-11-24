/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** GetPool.cpp
*/

#ifndef RTYPE_UTIL_HPP
#define RTYPE_UTIL_HPP

#include "ObjectPool.hpp"
#include "EntityAdmin.hpp"
#include "Entity.hpp"

namespace ecs
{
    template<typename T>
    ObjectPool<T> &GetPool(const std::shared_ptr<EntityAdmin> &admin)
    {
        return std::get<ObjectPool<T>>(admin->pools);
    }

    template<typename ...Args>
    void createEntity(const std::shared_ptr<EntityAdmin> &admin, Args *...args)
    {
        admin->entities.emplace_back(new Entity<Args ...>(args...));
    }
}

#endif
