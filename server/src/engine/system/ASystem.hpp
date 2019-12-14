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
        T &get(Tuple &tuple)
        {
            return GetFromTuple<T>(tuple, admin);
        }

    protected:
        std::shared_ptr<EntityAdmin> admin;
    };
}

#endif
