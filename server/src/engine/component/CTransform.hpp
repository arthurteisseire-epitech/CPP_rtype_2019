/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CTransform.hpp
*/

#ifndef RTYPE_CTRANSFORM_HPP
#define RTYPE_CTRANSFORM_HPP

#include "Vector2.hpp"

namespace ecs
{
    struct CTransform {
        explicit CTransform(int x = 0, int y = 0) : vec(x, y)
        {
        }

        explicit CTransform(const mut::Vec2f &vec) : vec(vec)
        {
        }

        mut::Vec2f vec;
    };
}

#endif
