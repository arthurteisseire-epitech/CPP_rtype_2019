/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** EntityTest.cpp
*/

#include "gtest/gtest.h"
#include "ObjectPool.hpp"
#include "Entity.hpp"
#include "EntityFactory.hpp"

using namespace ecs;

TEST(Entity, destroy)
{
    auto admin = std::make_shared<EntityAdmin>();
//    EntityFactory::createPlayer(admin, GetPool<CConnection>(admin).create(boost::asio::ip::udp::endpoint()));

//    admin->entities.at(0)->destroy(admin);

    EXPECT_EQ(GetPool<CConnection>(admin).begin(), GetPool<CConnection>(admin).end());
}

TEST(Entity, destroy2)
{
    auto admin = std::make_shared<EntityAdmin>();

//    for (int i = 0; i < 3; ++i) {
//        EntityFactory::createPlayer(admin, GetPool<CConnection>(admin).create(boost::asio::ip::udp::endpoint()));
//        GetPool<CTransform>(admin).at(ObjectPool<CTransform>::index(i)).vec.x = i;
//    }

//    admin->entities.at(0)->destroy(admin);

    EXPECT_EQ(GetPool<CConnection>(admin).begin(), GetPool<CConnection>(admin).end());
}
