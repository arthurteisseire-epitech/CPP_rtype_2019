/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** main.cpp
*/

#include <thread>
#include "EntityAdmin.hpp"
#include "SystemUtil.hpp"
#include "ReceiveSystem.hpp"

int main()
{
    auto admin = std::make_shared<ecs::EntityAdmin>();
    ecs::ReceiveSystem connSystem(admin);
    auto systems = ecs::SystemsUtil::Init(admin);

    std::thread t([&]() {
        connSystem.update(0.16);
    });
    while (true) {
        ecs::SystemsUtil::Update(systems, 0.16);
        std::this_thread::sleep_for(std::chrono::milliseconds(160));
    }
    t.join();
    std::cout << "end" << std::endl;
}
