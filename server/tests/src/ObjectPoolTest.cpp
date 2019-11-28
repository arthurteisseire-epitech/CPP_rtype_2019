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
    ecs::ObjectPool<ecs::HealthComponent> healthComponentPool;

    auto p = healthComponentPool.create();

    ASSERT_TRUE(p != nullptr);
}

TEST(ComponentPool, createWithArgs)
{
    ecs::ObjectPool<ecs::HealthComponent> healthComponentPool;

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

TEST(ComponentPool, iterate)
{
    ecs::ObjectPool<ecs::HealthComponent> healthComponentPool;
    int nbComponents = 3;
    int actualNbComponents = 0;

    for (int i = 0; i < nbComponents; ++i)
        healthComponentPool.create();
    for (auto &pool : healthComponentPool)
        ++actualNbComponents;

    EXPECT_EQ(actualNbComponents, nbComponents);
}

TEST(ComponentPool, addExistingComponent)
{
    ecs::ObjectPool<ecs::HealthComponent> healthComponentPool;
    auto p = ecs::HealthComponent();

    healthComponentPool.move(std::move(p));

    int count = 0;
    for (auto &c : healthComponentPool)
        ++count;
    EXPECT_EQ(count, 1);
}
