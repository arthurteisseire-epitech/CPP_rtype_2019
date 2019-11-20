/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SystemTest.cpp
*/

#include "gtest/gtest.h"
#include "ObjectPool.hpp"
#include "HealthSystem.hpp"
#include "TransformSystem.hpp"
#include "TransformComponent.hpp"

TEST(System, updateHealth)
{
    auto admin = std::make_shared<ecs::EntityAdmin>();
    ecs::HealthSystem healthSystem(admin);
    auto healthComponent = admin->getPool<ecs::HealthComponent>().create(100);

    healthSystem.update(0.16);

    ASSERT_EQ(healthComponent->life, 80);
}

TEST(System, updateTransform)
{
    auto admin = std::make_shared<ecs::EntityAdmin>();
    ecs::TransformSystem transformSystem(admin);
    auto transformComponent = admin->getPool<ecs::TransformComponent>().create(100);

    transformSystem.update(0.16);

    ASSERT_EQ(transformComponent->x, 2);
}
