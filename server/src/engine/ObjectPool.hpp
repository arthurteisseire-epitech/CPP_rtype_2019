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
        explicit ObjectPool(int padSize = 20) :
            padSize(padSize),
            pool()
        {
            reallocate();
        }

        template<typename ...Args>
        std::size_t create(Args ...args)
        {
            std::lock_guard<std::mutex> lock(mutex);

            if (pool.size() == pool.capacity())
                reallocate();
            pool.emplace_back(args...);
            return pool.size() - 1;
        }

        std::size_t move(T &&obj)
        {
            std::lock_guard<std::mutex> lock(mutex);

            if (pool.size() == pool.capacity())
                reallocate();
            pool.push_back(std::move(std::forward<T>(obj)));
            return pool.size() - 1;
        }

        void destroy(std::size_t idx)
        {
            std::lock_guard<std::mutex> lock(mutex);

            std::iter_swap(pool.begin() + idx, std::prev(pool.end()));
            pool.pop_back();
        }

        T &at(std::size_t idx)
        {
            return pool.at(idx);
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
