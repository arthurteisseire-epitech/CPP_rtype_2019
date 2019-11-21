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
    ecs::EntityAdmin admin;
    auto healthComponent = admin.getPool<ecs::HealthComponent>().create(100);

    ecs::HealthSystem::update(0.16, admin);

    EXPECT_EQ(healthComponent->life, 80);
}

TEST(System, updateTransform)
{
    ecs::EntityAdmin admin;
    auto transformComponent = admin.getPool<ecs::TransformComponent>().create();

    ecs::TransformSystem::update(0.16, admin);

    EXPECT_EQ(transformComponent->x, 2);
}
