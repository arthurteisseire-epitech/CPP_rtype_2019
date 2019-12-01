/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Entity.hpp
*/

#ifndef RTYPE_ENTITY_HPP
#define RTYPE_ENTITY_HPP

#include <tuple>
#include "Util.hpp"
#include "IEntity.hpp"
#include "TupleTypeUtil.hpp"
#include "Id.hpp"

namespace ecs
{
    template<typename ...Args>
    class Entity : public IEntity {
    public:
        explicit Entity(std::shared_ptr<EntityAdmin> &admin, Args... args) :
            components(args...)
        {
            id = nextId();

            tuples = std::apply([&](auto ...tupleIdx) {
                return std::make_tuple(createTuple<typename decltype(tupleIdx)::type>(admin)...);
            }, tuples);
        }

        template <typename Tuple>
        auto createTuple(std::shared_ptr<EntityAdmin> &admin)
        {
            return std::apply([&](auto ...ts) {
                return std::get<ObjectPool<Tuple>>(admin->pools).create(std::get<decltype(ts)>(components)...);
            }, Tuple{});
        }

        template<typename T>
        T get()
        {
            return std::get<T>(tuples);
        }

        [[nodiscard]] int getId() const
        {
            return id;
        }

    private:
        std::tuple<Args...> components;
        EntityTuples<Args...> tuples;
        int id;
    };
}

#endif
