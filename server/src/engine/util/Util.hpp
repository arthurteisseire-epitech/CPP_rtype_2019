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

    template<typename Tuple, typename Func>
    void ForEachMatching(std::shared_ptr<EntityAdmin> &admin, Func f)
    {
        for (auto &t : GetPool<Tuple>(admin))
            f(t);
    }

    template<typename T, typename Tuple>
    typename ObjectPool<T>::index GetIndex(Tuple &t)
    {
        return std::get<typename ObjectPool<T>::index>(t);
    }
}

#endif
