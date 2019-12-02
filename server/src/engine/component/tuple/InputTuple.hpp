/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** InputTuple.hpp
*/

#ifndef RTYPE_INPUTTUPLE_HPP
#define RTYPE_INPUTTUPLE_HPP

#include "ObjectPool.hpp"
#include "CInput.hpp"
#include "CConnection.hpp"

namespace ecs
{
    using InputTuple = std::tuple
        <
            ObjectPool<CConnection>::index,
            ObjectPool<CInput>::index
        >;
}

#endif
