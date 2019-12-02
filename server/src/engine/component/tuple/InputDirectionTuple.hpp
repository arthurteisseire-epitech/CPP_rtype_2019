/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** InputDirectionTuple.hpp
*/

#ifndef RTYPE_INPUTDIRECTIONTUPLE_HPP
#define RTYPE_INPUTDIRECTIONTUPLE_HPP

#include <tuple>
#include "ObjectPool.hpp"
#include "CDirection.hpp"
#include "CInput.hpp"

namespace ecs
{
    using InputDirectionTuple = std::tuple
        <
            ObjectPool<CDirection>::index,
            ObjectPool<CInput>::index
        >;
}

#endif
