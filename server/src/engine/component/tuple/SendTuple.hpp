/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SendTuple.hpp
*/

#ifndef RTYPE_SENDTUPLE_HPP
#define RTYPE_SENDTUPLE_HPP

#include "TransformComponent.hpp"
#include "ConnectionComponent.hpp"

namespace ecs
{
    struct SendTuple {
        SendTuple(std::size_t connectionIdx, std::size_t transformIdx) :
            connectionIdx(connectionIdx),
            transformIdx(transformIdx)
        {
        }

        std::size_t connectionIdx;
        std::size_t transformIdx;
    };
}

#endif
