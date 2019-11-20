/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** EntityTest.cpp
*/

#include <TransformComponent.hpp>
#include "ObjectPool.hpp"
#include "gtest/gtest.h"
#include "Entity.hpp"
#include "HealthComponent.hpp"

TEST(Entity, getComponent)
{
    auto healthPool = ecs::ObjectPool<ecs::HealthComponent>();
    auto transformPool = ecs::ObjectPool<ecs::TransformComponent>();

    auto player = std::make_unique<ecs::Entity<ecs::HealthComponent, ecs::TransformComponent>>(
        healthPool.create(10),
        transformPool.create()
    );

    auto healthComponent = player->get<ecs::HealthComponent>();

    EXPECT_EQ(healthComponent->life, 10);
}

TEST(Entity, getMultipleComponents)
{
    auto healthPool = ecs::ObjectPool<ecs::HealthComponent>();
    auto transformPool = ecs::ObjectPool<ecs::TransformComponent>();

    auto player = std::make_unique<ecs::Entity<ecs::HealthComponent, ecs::TransformComponent>>(
        healthPool.create(10),
        transformPool.create()
    );

    auto components = player->getMany<ecs::TransformComponent, ecs::HealthComponent>();

    EXPECT_EQ(std::get<ecs::HealthComponent *>(components)->life, 10);
}
