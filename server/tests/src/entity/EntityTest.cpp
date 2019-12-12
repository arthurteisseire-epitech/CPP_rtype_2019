/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** EntityTest.cpp
*/

#include "gtest/gtest.h"
#include "EntityAdmin.hpp"
#include "ObjectPool.hpp"
#include "Entity.hpp"
#include "EntityFactory.hpp"

using namespace ecs;

TEST(Entity, destroyComponents)
{
    auto admin = std::make_shared<EntityAdmin>();
    auto &connPool = GetPool<CConnection>(admin);
    EntityFactory::createPlayer(admin, connPool.create(boost::asio::ip::udp::endpoint()));

    admin->entities.at(0)->destroy(admin);

    for (const auto &pair : connPool)
        EXPECT_EQ(pair.first, ecs::ObjectPool<CConnection>::AVAILABLE);
}

TEST(Entity, destroyTuples)
{
    auto admin = std::make_shared<EntityAdmin>();
    auto &cmdDirTuplePool = GetPool<CommandTuple>(admin);
    EntityFactory::createPlayer(admin, GetPool<CConnection>(admin).create(boost::asio::ip::udp::endpoint()));

    admin->entities.at(0)->destroy(admin);

    for (const auto &pair : cmdDirTuplePool)
        EXPECT_EQ(pair.first, ecs::ObjectPool<CommandTuple>::AVAILABLE);
}
