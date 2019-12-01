/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** MetaUtil.hpp
*/

#ifndef RTYPE_TUPLETYPEUTIL_HPP
#define RTYPE_TUPLETYPEUTIL_HPP

#include <tuple>
#include "MoveTuple.hpp"
#include "InputTuple.hpp"

namespace ecs
{
    template<typename T, typename Tuple>
    struct has_type;

    template<typename T, typename... Us>
    struct has_type<T, std::tuple<Us...>> : std::disjunction<std::is_same<T, Us>...> {};

    template<typename SubTuple, typename Tuple>
    struct has_types;

    template<typename ...T, typename Tuple>
    struct has_types<std::tuple<T...>, Tuple> : std::conjunction<has_type<T, Tuple>...> {};

    // TODO -- Template recursion seems to be a better way to achieve this
    template<typename IdxTuple, typename ...Ts>
    auto getTuplesMatching(const std::tuple<Ts...> &t)
    {
        return std::apply([](Ts...) {
            return std::tuple_cat(std::conditional_t<(has_types<Ts, IdxTuple>::value),
                                                     std::tuple<typename ObjectPool<Ts>::index>,
                                                     std::tuple<>
                                                    >{}...);
        }, t);
    }

    using TupleList = std::tuple
        <
            MoveTuple,
            InputTuple,
            SendRenderTuple
        >;

    template<typename ...Args>
    using EntityTuples = decltype(getTuplesMatching<decltype(std::tuple<Args...>{})>(TupleList{}));
}

#endif
