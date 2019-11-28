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
        explicit PlayerEntity(const std::shared_ptr<EntityAdmin> &admin, std::size_t connIdx)
        {
            auto transformIdx = GetPool<TransformComponent>(admin).create();
            auto dirIdx = GetPool<DirectionComponent>(admin).create();

            inputTupleIdx = GetPool<InputTuple>(admin).create(connIdx, transformIdx);
            moveTupleIdx = GetPool<MoveTuple>(admin).create(dirIdx, transformIdx);
            sendTupleIdx = GetPool<SendTuple>(admin).create(connIdx, transformIdx);
        }

        std::size_t inputTupleIdx;
        std::size_t moveTupleIdx;
        std::size_t sendTupleIdx;
        //        std::size_t id;
    };
}

#endif
