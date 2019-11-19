/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** PoolComponent.hpp
*/

#ifndef RTYPE_COMPONENTPOOL_HPP
#define RTYPE_COMPONENTPOOL_HPP

#include "HealthComponent.hpp"

namespace ecs
{
    template<typename T, int PadSize = 20>
    class ComponentPool {
    public:
        explicit ComponentPool()
        {
            reallocate();
        }

        T *create()
        {
            auto *component = findFreeComponent();

            if (component == nullptr)
                component = reallocate();
            return component;
        }

        T *findFreeComponent()
        {
            for (auto &p : pool)
                if (p.first == true)
                    return &p.second;
            return nullptr;
        }

        T *reallocate()
        {
            pool.reserve(pool.size() + PadSize);
            for (int i = 0; i < PadSize; ++i)
                pool.emplace_back(true, std::move(T()));
            return &pool.back().second;
        }

    private:
        std::vector<std::pair<bool, T>> pool;
    };
}

#endif
