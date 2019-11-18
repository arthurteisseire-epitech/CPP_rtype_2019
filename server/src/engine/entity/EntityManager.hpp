/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** EntityManager.hpp
*/

#ifndef RTYPE_ENTITYMANAGER_HPP
#define RTYPE_ENTITYMANAGER_HPP

#include <vector>
#include <unordered_map>
#include <tuple>
#include <memory>
#include "IComponent.hpp"
#include "Entity.hpp"

namespace ecs
{
    class EntityManager {
    public:

        template <typename ...Args>
        Entity createEntity()
        {
            map.emplace(nextEntity, make_unique_vector<IComponent, Args...>());
            return nextEntity++;
        }

        template<class T, class... Args>
        static std::vector<std::unique_ptr<T>> make_unique_vector()
        {
            std::unique_ptr<T> ini[] = {std::unique_ptr<Args>(new Args)...};

            std::vector<std::unique_ptr<T>> v{
                std::make_move_iterator(std::begin(ini)),
                std::make_move_iterator(std::end(ini))
            };
            return v;
        }

    private:
        std::unordered_map<Entity, std::vector<std::unique_ptr<IComponent>>> map;
        static Entity nextEntity;
    };
}

#endif
