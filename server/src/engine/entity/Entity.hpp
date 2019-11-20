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

namespace ecs
{
    template<typename ...Args>
    class Entity : public IEntity {
    public:
        explicit Entity(Args*... args) :
            components(args...)
        {
        }

        template <typename T>
        T *get()
        {
            return std::get<T *>(components);
        }

    private:
        std::tuple<Args*...> components;
    };
}

#endif
