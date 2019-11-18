/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ComponentPoolTest.cpp
*/

#include "gtest/gtest.h"
#include "ComponentPool.hpp"
#include "HealthComponent.hpp"

TEST(ComponentPool, init)
{
    ecs::ComponentPool<ecs::HealthComponent, 20> healthComponentPool;

    auto p = healthComponentPool.create();

    ASSERT_TRUE(p != nullptr);
}
