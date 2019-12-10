/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ComponentPoolTest.cpp
*/

#include "gtest/gtest.h"
#include "ObjectPool.hpp"
#include "CHealth.hpp"

TEST(ComponentPool, create)
{
    ecs::ObjectPool<ecs::CHealth> healthComponentPool;

    auto p = healthComponentPool.create();

    EXPECT_EQ(p.idx, 0);
}

TEST(ComponentPool, createWithArgs)
{
    ecs::ObjectPool<ecs::CHealth> healthComponentPool;

    auto p = healthComponentPool.create(20);

    EXPECT_TRUE(healthComponentPool.at(p).life == 20);
}

TEST(ComponentPool, destroy)
{
    ecs::ObjectPool<ecs::CHealth> healthComponentPool(10);
    auto p1 = healthComponentPool.create();
    auto p2 = healthComponentPool.create();

    healthComponentPool.destroy(p1);

    EXPECT_EQ(p1.idx + 1, p2.idx);
}


TEST(ComponentPool, destroyWithOnePadSize)
{
    ecs::ObjectPool<ecs::CHealth> healthComponentPool(1);
    auto p1 = healthComponentPool.create();

    healthComponentPool.destroy(p1);

    auto p2 = healthComponentPool.create();
    EXPECT_EQ(p1.idx, p2.idx);
}

TEST(ComponentPool, iterate)
{
    ecs::ObjectPool<ecs::CHealth> healthComponentPool;
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
    ecs::ObjectPool<ecs::CHealth> healthComponentPool;
    auto p = ecs::CHealth();

    healthComponentPool.move(std::move(p));

    int count = 0;
    for (auto &c : healthComponentPool)
        ++count;
    EXPECT_EQ(count, 1);
}
