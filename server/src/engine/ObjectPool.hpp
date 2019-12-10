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
#include <mutex>

namespace ecs
{
    template<typename T>
    class ObjectPool {
    public:
        struct index {
            explicit index(std::size_t idx = 0) : idx(idx)
            {
            }

            std::size_t idx;
            using type = T;
        };

        explicit ObjectPool(int padSize = 20) :
            padSize(padSize),
            pool()
        {
            reallocate();
        }

        template<typename ...Args>
        index create(Args&& ...args)
        {
            std::lock_guard<std::mutex> lock(mutex);

            if (pool.size() == pool.capacity())
                reallocate();
            pool.push_back({false, T(args...)});
            return index(pool.size() - 1);
        }

        index move(T &&obj)
        {
            std::lock_guard<std::mutex> lock(mutex);

            if (pool.size() == pool.capacity())
                reallocate();
            pool.push_back(std::move(std::forward<std::pair<bool, T>>({false, obj})));
            return index(pool.size() - 1);
        }

        void destroy(index idx)
        {
            std::lock_guard<std::mutex> lock(mutex);

            pool.at(idx.idx).first = true;
        }

        T &at(index idx)
        {
            std::lock_guard<std::mutex> lock(mutex);

            return pool.at(idx.idx).second;
        }

        auto begin()
        {
            return pool.begin();
        }

        auto end()
        {
            return pool.end();
        }

    private:

        void reallocate()
        {
            pool.reserve(pool.size() + padSize);
        }

        std::vector<std::pair<bool, T>> pool;
        std::mutex mutex;
        int padSize;
    };
}

#endif
