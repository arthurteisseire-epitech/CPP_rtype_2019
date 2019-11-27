/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include "ShootSystem.hpp"

ecs::ShootSystem::ShootSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(std::move(admin))
{}

void ecs::ShootSystem::update(float dt)
{
}
