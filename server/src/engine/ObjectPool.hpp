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
        };

        explicit ObjectPool(int padSize = 20) :
            padSize(padSize),
            pool()
        {
            reallocate();
        }

        template<typename ...Args>
        index create(Args ...args)
        {
            std::lock_guard<std::mutex> lock(mutex);

            if (pool.size() == pool.capacity())
                reallocate();
            pool.emplace_back(args...);
            return index(pool.size() - 1);
        }

        index move(T &&obj)
        {
            std::lock_guard<std::mutex> lock(mutex);

            if (pool.size() == pool.capacity())
                reallocate();
            pool.push_back(std::move(std::forward<T>(obj)));
            return index(pool.size() - 1);
        }

        void destroy(index idx)
        {
            std::lock_guard<std::mutex> lock(mutex);

            std::iter_swap(pool.begin() + idx.idx, std::prev(pool.end()));
            pool.pop_back();
        }

        T &at(index idx)
        {
            std::lock_guard<std::mutex> lock(mutex);

            return pool.at(idx.idx);
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
        std::mutex mutex;
        int padSize;
    };
}

#endif
