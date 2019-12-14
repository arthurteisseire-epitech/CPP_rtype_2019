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
#include "DynamicLoadMonsterSystem.hpp"

int main()
{
    auto admin = std::make_shared<ecs::EntityAdmin>();
    ecs::ReceiveSystem connSystem(admin);
    ecs::DynamicLoadMonsterSystem monsterLoader(admin);
    auto systems = ecs::SystemsUtil::Init(admin);

    std::thread t([&]() {
        connSystem.update(0.16);
    });
    std::thread t2([&]() {
        monsterLoader.update(0);
    });
    while (true) {
        ecs::SystemsUtil::Update(systems, 0.16);
        std::this_thread::sleep_for(std::chrono::milliseconds(160));
    }
    t.join();
    t2.join();
    std::cout << "end" << std::endl;
}
