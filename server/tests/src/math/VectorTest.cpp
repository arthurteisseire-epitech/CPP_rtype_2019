/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include "gtest/gtest.h"
#include "Vector2.hpp"

TEST(Vector, init)
{
    mut::Vec2f vec(3, 4);

    EXPECT_EQ(vec.x, 3);
    EXPECT_EQ(vec.y, 4);
}

void addTest(mut::Vec2f vec1, mut::Vec2f vec2, mut::Vec2f res)
{
    EXPECT_EQ(vec1 + vec2, res);
}

TEST(Vector, add)
{
    addTest({1, 2}, {0, 0}, {1, 2});
    addTest({1, 2}, {3, 4}, {4, 6});
    addTest({1, 2}, {-3, -4}, {-2, -2});
}

void subTest(mut::Vec2f vec1, mut::Vec2f vec2, mut::Vec2f res)
{
    EXPECT_EQ(vec1 - vec2, res);
}

TEST(Vector, sub)
{
    subTest({1, 2}, {0, 0}, {1, 2});
    subTest({1, 2}, {3, 4}, {-2, -2});
    subTest({1, 2}, {-3, -4}, {4, 6});
}