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
        explicit ObjectPool()
        {
            reallocate();
        }

        T *create()
        {
            auto it = std::find_if(pool.begin(), pool.end(), [](const std::pair<Memory, T> &p) {
                return p.first == AVAILABLE;
            });

            if (it == pool.end()) {
                reallocate();
                it = std::prev(pool.end());
            }
            it->first = UNAVAILABLE;
            return &it->second;
        }

        void destroy(T *obj)
        {
            auto it = std::find_if(pool.begin(), pool.end(), [obj](const std::pair<Memory, T> &p) {
                return obj == &p.second;
            });
            it->first = AVAILABLE;
        }

    private:

        void reallocate()
        {
            pool.reserve(pool.size() + PadSize);
            for (int i = 0; i < PadSize; ++i)
                pool.emplace_back(AVAILABLE, std::move(T()));
        }

        enum Memory {
            AVAILABLE,
            UNAVAILABLE
        };
        std::vector<std::pair<Memory, T>> pool;
    };
}

#endif
