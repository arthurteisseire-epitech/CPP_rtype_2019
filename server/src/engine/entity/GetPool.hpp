/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** GetPool.cpp
*/

#include "ObjectPool.hpp"
#include "EntityAdmin.hpp"

namespace ecs
{
    template<typename T>
    ObjectPool<T> &GetPool(const std::shared_ptr<EntityAdmin> &admin)
    {
        return std::get<ObjectPool<T>>(admin->pools);
    }
}
