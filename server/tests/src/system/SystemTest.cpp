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
    ecs::EntityAdmin admin;
    auto healthComponent = ecs::GetPool<ecs::HealthComponent>(admin).create(100);

    ecs::HealthSystem::update(0.16, admin);

    EXPECT_EQ(healthComponent->life, 80);
}

TEST(System, updateTransform)
{
    ecs::EntityAdmin admin;
    auto transformComponent = ecs::GetPool<ecs::TransformComponent>(admin).create();

    ecs::TransformSystem::update(0.16, admin);

    EXPECT_EQ(transformComponent->x, 2);
}
