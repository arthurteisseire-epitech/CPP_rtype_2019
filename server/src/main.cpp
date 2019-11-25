/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** main.cpp
*/

#include <thread>
#include "InputSystem.hpp"
#include "SendSystem.hpp"
#include "MoveSystem.hpp"
#include "ConnectionSystem.hpp"
#include "EntityAdmin.hpp"
#include "InputTuple.hpp"

int main()
{
    auto admin = std::make_shared<ecs::EntityAdmin>();
    ecs::ConnectionSystem connSystem(admin);
    ecs::InputSystem inputSystem(admin);
    ecs::SendSystem sendSystem(admin);
    ecs::MoveSystem moveSystem(admin);

    std::thread t([&]() {
        connSystem.update(0.16);
    });
    while (true) {
        inputSystem.update(0.16);
        moveSystem.update(0.16);
        sendSystem.update(0.16);
        sleep(1);
    }
    t.join();
    std::cout << "end" << std::endl;
}
