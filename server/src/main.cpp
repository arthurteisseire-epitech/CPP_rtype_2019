/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** main.cpp
*/

#include <thread>
#include "ConnectionSystem.hpp"
#include "GetPool.hpp"
#include "EntityAdmin.hpp"

int main()
{
    auto admin = std::make_shared<ecs::EntityAdmin>();
    ecs::ConnectionSystem connSystem(admin);

    std::thread t([&]() {
        connSystem.update(0.16);
    });
    t.join();
    std::cout << "end" << std::endl;
}
