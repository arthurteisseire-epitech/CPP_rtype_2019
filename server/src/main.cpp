/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** main.cpp
*/

#include "ConnectionSystem.hpp"
#include "GetPool.hpp"
#include "EntityAdmin.hpp"

int main()
{
    auto admin = std::make_shared<ecs::EntityAdmin>();
    ecs::ConnectionSystem connSystem(admin);

    connSystem.update(0.16);
    std::cout << "end" << std::endl;
}
