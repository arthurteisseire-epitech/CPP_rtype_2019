/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_MOVETUPLE_HPP
#define RTYPE_MOVETUPLE_HPP

#include "DirectionComponent.hpp"
#include "TransformComponent.hpp"

namespace ecs
{
    struct MoveTuple {
        MoveTuple(std::size_t directionIdx, std::size_t transformIdx) :
            directionIdx(directionIdx),
            transformIdx(transformIdx)
        {
        }

        std::size_t directionIdx;
        std::size_t transformIdx;
    };
}

#endif
