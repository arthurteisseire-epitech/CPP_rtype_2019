/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SystemTest.cpp
*/

#include "gtest/gtest.h"
#include "DirectionComponent.hpp"
#include "MoveSystem.hpp"
#include "ObjectPool.hpp"
#include "MoveTuple.hpp"
#include "TransformComponent.hpp"
#include "GetPool.hpp"

TEST(System, move)
{
    auto admin = std::make_shared<ecs::EntityAdmin>();
    auto transformComponent = ecs::GetPool<ecs::TransformComponent>(admin).create(20, 20);
    auto directionComponent = ecs::GetPool<ecs::DirectionComponent>(admin).create();
    auto moveTuple = ecs::GetPool<ecs::MoveTuple>(admin).create(directionComponent, transformComponent);
    ecs::MoveSystem moveSystem(admin);

    directionComponent->setDirection(ecs::DirectionComponent::DOWN);
    ASSERT_EQ(transformComponent->vec, mut::Vec2f(20, 20));
    moveSystem.update(0.16);
    EXPECT_EQ(transformComponent->vec, mut::Vec2f(20, 19));
}