/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ASystem.hpp
*/

#ifndef RTYPE_ASYSTEM_HPP
#define RTYPE_ASYSTEM_HPP

#include <utility>
#include "EntityAdmin.hpp"
#include "Entity.hpp"

namespace ecs
{
    class ASystem {
    public:
        explicit ASystem(std::shared_ptr<EntityAdmin> admin) :
            admin(std::move(admin))
        {
        }

        virtual void update(float deltaTime) = 0;

        template<class T, class Tuple>
        std::conditional_t<has_type<typename ObjectPool<T>::index, Tuple>::value, T, const T> &get(Tuple &tuple)
        {
            using type = std::conditional_t
                <
                    has_type<typename ObjectPool<T>::index, Tuple>::value,
                    typename ObjectPool<T>::index,
                    const typename ObjectPool<T>::index
                >;

            return std::get<ObjectPool<T>>(admin->pools).at(std::get<type>(tuple));
        }

    protected:
        std::shared_ptr<EntityAdmin> admin;
    };
}

#endif
