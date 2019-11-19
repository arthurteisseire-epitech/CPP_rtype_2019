/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** PoolComponent.hpp
*/

#ifndef RTYPE_OBJECTPOOL_HPP
#define RTYPE_OBJECTPOOL_HPP

#include <algorithm>
#include <vector>
#include <iostream>

namespace ecs
{
    template<typename T, int PadSize = 20>
    class ObjectPool {
    public:
        explicit ObjectPool() :
            pool()
        {
            reallocate();
        }

        template<typename ...Args>
        T *create(Args ...args)
        {
            if (pool.size() == pool.capacity())
                reallocate();
            pool.emplace_back(args...);
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

        std::vector<T> &get()
        {
            return pool;
        }

    private:

        void reallocate()
        {
            pool.reserve(pool.size() + PadSize);
        }

        std::vector<T> pool;
    };
}

#endif
