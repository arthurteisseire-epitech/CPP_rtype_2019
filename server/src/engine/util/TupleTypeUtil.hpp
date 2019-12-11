/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** MetaUtil.hpp
*/

#ifndef RTYPE_TUPLETYPEUTIL_HPP
#define RTYPE_TUPLETYPEUTIL_HPP

#include <tuple>
#include "TupleList.hpp"
#include "ComponentList.hpp"

namespace ecs
{
    template<typename T, typename Tuple>
    struct has_type;

    template<typename T, typename... Us>
    struct has_type<T, std::tuple<Us...>> : std::disjunction<std::is_same<T, Us>...> {};

    template<typename SubTuple, typename Tuple>
    struct has_types;

    template<typename ...T, typename Tuple>
    struct has_types<std::tuple<T...>, Tuple> : std::conjunction<has_type<std::remove_const_t<T>, Tuple>...> {};

    // TODO -- Template recursion seems to be a better way to achieve this
    template<typename IdxTuple, typename ...Ts>
    auto getTuplesMatching(const std::tuple<Ts...> &t)
    {
        return std::apply([](Ts...) {
            return std::tuple_cat(std::conditional_t<has_types<Ts, IdxTuple>::value,
                                                     std::tuple<typename ObjectPool<Ts>::index>,
                                                     std::tuple<>
                                                    >{}...);
        }, t);
    }

    template<typename Tuple, typename ...Args>
    using ComponentsTuples = decltype(getTuplesMatching<decltype(std::tuple<Args...>{})>(Tuple{}));


    template<typename Tuple>
    struct rebindToPools;

    template<typename ...T>
    struct rebindToPools<std::tuple<T...>> {
        using type = decltype(std::tuple<ObjectPool<T>...>{});
    };

    using TuplePools = rebindToPools<TupleList>::type;
    using ComponentPools = rebindToPools<ComponentList>::type;
}

#endif
