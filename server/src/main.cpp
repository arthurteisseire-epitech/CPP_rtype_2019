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
    ecs::EntityAdmin admin;

    ecs::ConnectionSystem::update(0.16, admin);


}
