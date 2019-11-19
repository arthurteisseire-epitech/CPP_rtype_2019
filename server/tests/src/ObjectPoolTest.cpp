/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ComponentPoolTest.cpp
*/

#include "gtest/gtest.h"
#include "ObjectPool.hpp"
#include "HealthComponent.hpp"

TEST(ComponentPool, create)
{
    ecs::ObjectPool<ecs::HealthComponent, 10> healthComponentPool;

    auto p = healthComponentPool.create();

    ASSERT_TRUE(p != nullptr);
}

TEST(ComponentPool, createWithArgs)
{
    ecs::ObjectPool<ecs::HealthComponent, 10> healthComponentPool;

    auto p = healthComponentPool.create(20);

    ASSERT_TRUE(p->life == 20);
}

TEST(ComponentPool, destroy)
{
    ecs::ObjectPool<ecs::HealthComponent> healthComponentPool;
    auto p = healthComponentPool.create();

    healthComponentPool.destroy(p);
    ASSERT_EQ(p, healthComponentPool.create());
}
