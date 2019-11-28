/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** PlayerEntity.hpp
*/

#ifndef RTYPE_PLAYERENTITY_HPP
#define RTYPE_PLAYERENTITY_HPP

#include <cstddef>
#include <tuple/InputTuple.hpp>
#include <Util.hpp>
#include "IEntity.hpp"

namespace ecs
{
    struct PlayerEntity : public IEntity {
        explicit PlayerEntity(const std::shared_ptr<EntityAdmin> &admin, ObjectPool<ConnectionComponent>::index connIdx)
        {
            auto transformIdx = GetPool<TransformComponent>(admin).create();
            auto dirIdx = GetPool<DirectionComponent>(admin).create();

            inputTupleIdx = GetPool<InputTuple>(admin).create(connIdx, dirIdx);
            moveTupleIdx = GetPool<MoveTuple>(admin).create(dirIdx, transformIdx);
            sendTupleIdx = GetPool<SendTuple>(admin).create(connIdx, transformIdx);
        }

        ObjectPool<InputTuple>::index inputTupleIdx;
        ObjectPool<MoveTuple>::index moveTupleIdx;
        ObjectPool<SendTuple>::index sendTupleIdx;
        //        std::size_t id;
    };
}

#endif
