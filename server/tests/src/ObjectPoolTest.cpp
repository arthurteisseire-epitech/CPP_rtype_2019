/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ComponentPoolTest.cpp
*/

#include "gtest/gtest.h"
#include "ObjectPool.hpp"
#include "HealthComponent.hpp"

TEST(ComponentPool, init)
{
    ecs::ObjectPool<ecs::HealthComponent, 20> healthComponentPool;

    auto p = healthComponentPool.create();

    ASSERT_TRUE(p != nullptr);
}
