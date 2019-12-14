/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SystemThread.hpp
*/

#ifndef RTYPE_SYSTEMTHREADPOOL_HPP
#define RTYPE_SYSTEMTHREADPOOL_HPP

#include <thread>
#include <vector>
#include <memory>
#include "ASystem.hpp"

namespace ecs
{

    template <typename ...Args>
    class SystemThreadPool {
    private:
        class SystemThread {
        public:
            explicit SystemThread(ASystem *sys) :
                system(sys),
                thread([this]() {system->update(0);})
            {
            }

        private:
            std::thread thread;
            std::unique_ptr<ASystem> system;
        };

    public:
        explicit SystemThreadPool(std::shared_ptr<EntityAdmin> &admin)
        {
            pool.reserve(sizeof...(Args));

            (pool.emplace_back(new Args(admin)), ...);
        }

    private:
        std::vector<SystemThread> pool;
    };
}

#endif
