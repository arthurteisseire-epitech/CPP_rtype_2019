/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Entity.hpp
*/

#ifndef RTYPE_ENTITY_HPP
#define RTYPE_ENTITY_HPP

#include <tuple>
#include "IEntity.hpp"
#include "Id.hpp"

namespace ecs
{
    template<typename ...Args>
    class Entity : public IEntity {
    public:
        explicit Entity(Args ... args) :
            tuples(args...)
        {
            id = nextId();
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
        std::tuple<Args ...> tuples;
        int id;
    };
}

#endif
