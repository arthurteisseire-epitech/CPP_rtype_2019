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
#include "GetPool.hpp"

TEST(System, updateHealth)
{
    auto admin = std::make_shared<ecs::EntityAdmin>();
    auto healthComponent = ecs::GetPool<ecs::HealthComponent>(admin).create(100);
    ecs::HealthSystem healthSystem(admin);

    healthSystem.update(0.16);

    EXPECT_EQ(healthComponent->life, 80);
}

TEST(System, updateTransform)
{
    auto admin = std::make_shared<ecs::EntityAdmin>();
    auto transformComponent = ecs::GetPool<ecs::TransformComponent>(admin).create(100);
    ecs::TransformSystem transformSystem(admin);

    transformSystem.update(0.16);

    EXPECT_EQ(transformComponent->x, 2);
}
