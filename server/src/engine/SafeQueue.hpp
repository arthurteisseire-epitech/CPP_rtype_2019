/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SafeQueue.hpp
*/

#ifndef RTYPE_SAFEQUEUE_HPP
#define RTYPE_SAFEQUEUE_HPP

#include <queue>
#include <mutex>
#include <condition_variable>

namespace ecs
{
    template<class T>
    class SafeQueue {
    public:
        void push(T t)
        {
            std::lock_guard<std::mutex> lock(mutex);

            queue.push(t);
            cond.notify_one();
        }

        template <typename ...Args>
        void emplace(Args&& ...args)
        {
            push(T(std::forward<Args>(args)...));
        }

        T pop()
        {
            std::unique_lock<std::mutex> lock(mutex);

            while (queue.empty())
                cond.wait(lock);
            T val = queue.front();
            queue.pop();
            return val;
        }

    private:
        std::queue<T> queue;
        mutable std::mutex mutex;
        std::condition_variable cond;
    };
}


#endif
