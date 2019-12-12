/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** GetPool.cpp
*/

#ifndef RTYPE_UTIL_HPP
#define RTYPE_UTIL_HPP

#include <optional>
#include "ObjectPool.hpp"
#include "EntityAdmin.hpp"

namespace ecs
{
    template<typename T>
    ObjectPool <T> &GetPool(const std::shared_ptr<EntityAdmin> &admin)
    {
        return std::get<ObjectPool<T>>(admin->pools);
    }

    template<typename Tuple, typename Func>
    void ForEachMatching(std::shared_ptr<EntityAdmin> &admin, Func f)
    {
        for (auto &t : GetPool<Tuple>(admin))
            if (t.first == ObjectPool<Tuple>::UNAVAILABLE)
                f(t.second);
    }

    template<typename T, typename Tuple>
    typename ObjectPool<T>::index GetIndex(Tuple &t)
    {
        return std::get<typename ObjectPool<T>::index>(t);
    }

    template<typename Tuple>
    std::optional<std::reference_wrapper<Tuple>> GetById(std::shared_ptr<EntityAdmin> &admin, unsigned int entityId)
    {
        for (auto &t : GetPool<Tuple>(admin)) {
            if (t.first == ObjectPool<Tuple>::UNAVAILABLE &&
                GetPool<CId>(admin).at(GetIndex<CId>(t.second)).id == entityId) {
                return {t.second};
            }
        }
        return std::nullopt;
    }
}

#endif
