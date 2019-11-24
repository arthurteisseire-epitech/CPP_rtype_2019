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
    template<typename T>
    class ObjectPool {
    public:
        explicit ObjectPool(int padSize = 20) :
            padSize(padSize),
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

        T &move(T &&obj)
        {
            if (pool.size() == pool.capacity())
                reallocate();
            pool.push_back(std::move(std::forward<T>(obj)));
            return pool.back();
        }

        void destroy(T *obj)
        {
            auto it = std::find_if(pool.begin(), pool.end(), [obj](const T &p) {
                return obj == &p;
            });
            std::iter_swap(it, std::prev(pool.end()));
            pool.pop_back();
        }

        typename std::vector<T>::iterator begin()
        {
            return pool.begin();
        }

        typename std::vector<T>::iterator end()
        {
            return pool.end();
        }

    private:

        void reallocate()
        {
            pool.reserve(pool.size() + padSize);
        }

        std::vector<T> pool;
        int padSize;
    };
}

#endif
