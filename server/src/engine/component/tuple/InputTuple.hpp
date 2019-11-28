/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** InputTuple.hpp
*/

#ifndef RTYPE_INPUTTUPLE_HPP
#define RTYPE_INPUTTUPLE_HPP

#include "DirectionComponent.hpp"
#include "ConnectionComponent.hpp"

namespace ecs
{
    struct InputTuple {
        InputTuple(std::size_t connectionIdx, std::size_t directionIdx) :
            connectionIdx(connectionIdx),
            directionIdx(directionIdx)
        {
        }

        std::size_t connectionIdx;
        std::size_t directionIdx;
    };
}

#endif
