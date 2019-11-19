/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** PoolComponent.hpp
*/

#ifndef RTYPE_OBJECTPOOL_HPP
#define RTYPE_OBJECTPOOL_HPP

#include <algorithm>
#include "HealthComponent.hpp"

namespace ecs
{
    template<typename T, int PadSize = 20>
    class ObjectPool {
    public:
        explicit ObjectPool() :
            sizeAllocated(0)
        {
            reallocate();
        }

        T *create()
        {
            if (pool.size() == sizeAllocated)
                reallocate();
            pool.emplace_back();
            return &pool.back();
        }

        void destroy(T *obj)
        {
            auto it = std::find_if(pool.begin(), pool.end(), [obj](const T &p) {
                return obj == &p;
            });
            std::iter_swap(it, std::prev(pool.end()));
            pool.pop_back();
        }

    private:

        void reallocate()
        {
            sizeAllocated += PadSize;
            pool.reserve(sizeAllocated);
        }

        std::vector<T> pool;
        int sizeAllocated;
    };
}

#endif
