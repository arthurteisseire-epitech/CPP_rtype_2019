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
        enum MEMORY {AVAILABLE, UNAVAILABLE};

        struct index {
            explicit index(std::size_t idx = 0) :
                idx(idx)
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
        index create(Args &&...args)
        {
            std::lock_guard<std::mutex> lock(mutex);
            typename std::vector<std::pair<MEMORY, T>>::iterator it;

            if (pool.size() == pool.capacity()) {
                it = emplaceOnFreeSpace(args...);
                if (it != pool.end())
                    return index(it - pool.begin());
                reallocate();
            }
            pool.push_back({UNAVAILABLE, T(args...)});
            return index(pool.size() - 1);
        }

        template<typename ...Args>
        typename std::vector<std::pair<MEMORY, T>>::iterator emplaceOnFreeSpace(Args &&...args)
        {
            auto it = std::find_if(pool.begin(), pool.end(), [](auto &pair) {
                return pair.first == AVAILABLE;
            });
            if (it != pool.end())
                *it = {UNAVAILABLE, T(args...)};
            return it;
        }

        index move(T &&obj)
        {
            std::lock_guard<std::mutex> lock(mutex);

            if (pool.size() == pool.capacity())
                reallocate();
            pool.push_back(std::move(std::forward<std::pair<MEMORY, T>>({UNAVAILABLE, obj})));
            return index(pool.size() - 1);
        }
        void destroy(index idx)
        {
            std::lock_guard<std::mutex> lock(mutex);

            pool.at(idx.idx).first = AVAILABLE;
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

        std::vector<std::pair<MEMORY, T>> pool;
        std::mutex mutex;
        int padSize;
    };
}

#endif
