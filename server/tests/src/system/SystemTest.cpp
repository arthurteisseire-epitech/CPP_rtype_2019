/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SystemTest.cpp
*/

#include "gtest/gtest.h"
#include "ObjectPool.hpp"
#include "HealthSystem.hpp"

TEST(System, update)
{
    auto admin = std::make_shared<ecs::EntityAdmin>();
    ecs::HealthSystem healthSystem(admin);
    auto healthComponent = admin->getHealthPool().create(100);

    healthSystem.update(0.16);

    ASSERT_EQ(healthComponent->life, 80);
}
