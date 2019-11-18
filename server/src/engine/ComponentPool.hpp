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
    template<typename T>
    class ComponentPool {
    public:
        explicit ComponentPool(int padSize) :
            padSize(padSize)
        {
            reallocate();
        }

        T *create()
        {
            auto *component = findFreeComponent();

            if (component == nullptr) {
                reallocate();
                component = findFreeComponent();
            }
            return component;
        }

        T *findFreeComponent()
        {
            for (auto &p : pool)
                if (p.first == true)
                    return &p.second;
            return nullptr;
        }

        void reallocate()
        {
            pool.reserve(pool.size() + padSize);
            for (int i = 0; i < padSize; ++i)
                pool.emplace_back(true, std::move(T()));
        }

    private:
        int padSize;
        std::vector<std::pair<bool, T>> pool;
    };
}

#endif
