/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** main.cpp
*/

#include <thread>
#include "EntityAdmin.hpp"
#include "SystemUtil.hpp"
#include "ConnectionSystem.hpp"

int main()
{
    auto admin = std::make_shared<ecs::EntityAdmin>();
    ecs::ConnectionSystem connSystem(admin);
    auto systems = ecs::SystemsUtil::Init(admin);

    std::thread t([&]() {
        connSystem.update(0.16);
    });
    while (true) {
        inputSystem.update(0.16);
        moveSystem.update(0.16);
        sendSystem.update(0.16);
        usleep(160000);
        ecs::SystemsUtil::Update(systems, 0.16);
        sleep(1);
    }
    t.join();
    std::cout << "end" << std::endl;
}
