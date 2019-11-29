/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** EntityTest.cpp
*/

#include "ObjectPool.hpp"
#include "gtest/gtest.h"
#include "Entity.hpp"
#include "CHealth.hpp"
#include "CTransform.hpp"

TEST(Entity, create)
{
    auto healthPool = ecs::ObjectPool<ecs::CHealth>();
    auto transformPool = ecs::ObjectPool<ecs::CTransform>();

    auto entity1 = std::make_unique<ecs::Entity<ecs::CHealth, ecs::CTransform>>(
        healthPool.create(10),
        transformPool.create()
    );

    auto entity2 = std::make_unique<ecs::Entity<ecs::CHealth>>(
        healthPool.create()
    );

    EXPECT_EQ(entity2->getId(), entity1->getId() + 1);
}

TEST(Entity, getComponent)
{
    auto healthPool = ecs::ObjectPool<ecs::CHealth>();
    auto transformPool = ecs::ObjectPool<ecs::CTransform>();

    auto player = std::make_unique<ecs::Entity<ecs::CHealth, ecs::CTransform>>(
        healthPool.create(10),
        transformPool.create()
    );

    auto healthComponent = player->get<ecs::CHealth>();

    EXPECT_EQ(healthComponent->life, 10);
}
