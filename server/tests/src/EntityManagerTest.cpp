/*
** EPITECH PROJECT, 2019
** babel
** File description:
** EntityManagerTest.cpp
*/

#include "gtest/gtest.h"
#include "EntityManager.hpp"
#include "HealthComponent.hpp"
#include "TransformComponent.hpp"

TEST(EntityManagerTest, create)
{
    ecs::EntityManager entityManager;
    auto e1 = entityManager.createEntity<ecs::HealthComponent, ecs::TransformComponent>();
    auto e2 = entityManager.createEntity<ecs::HealthComponent>();

	ASSERT_GT(e2, e1);
}
