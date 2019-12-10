/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Types.hpp
*/

#ifndef RTYPE_TYPES_HPP
#define RTYPE_TYPES_HPP

#include "TupleTypeUtil.hpp"

namespace ecs
{
    template <typename ...Args>
    using EntityTuples = ComponentsTuples<TupleList, Args...>;

    using Pools = decltype(std::tuple_cat(TuplePools{}, ComponentPools{}));
}

#endif
