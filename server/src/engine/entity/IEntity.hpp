/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** IEntity.hpp
*/

#ifndef RTYPE_IENTITY_HPP
#define RTYPE_IENTITY_HPP

namespace ecs
{
    class EntityAdmin;
    class IEntity {
    public:
        ~IEntity() = default;
        virtual void destroy(std::shared_ptr<EntityAdmin> &admin) = 0;
    };
}

#endif
