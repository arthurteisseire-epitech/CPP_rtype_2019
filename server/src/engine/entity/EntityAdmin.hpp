/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** EntityAdmin.hpp
*/

#ifndef RTYPE_ENTITYADMIN_HPP
#define RTYPE_ENTITYADMIN_HPP

#include <tuple>
#include "SendRenderTuple.hpp"
#include "CConnection.hpp"
#include "CTransform.hpp"
#include "ObjectPool.hpp"
#include "CHealth.hpp"
#include "CNetwork.hpp"
#include "CType.hpp"
#include "CId.hpp"
#include "MoveTuple.hpp"
#include "InputTuple.hpp"
#include "IEntity.hpp"

namespace ecs
{
    struct EntityAdmin {
        EntityAdmin() :
            network(1234)
        {
        }

        std::tuple<
            ObjectPool<CConnection>,
            ObjectPool<CDirection>,
            ObjectPool<CTransform>,
            ObjectPool<CType>,
            ObjectPool<CId>,
            ObjectPool<InputTuple>,
            ObjectPool<SendRenderTuple>,
            ObjectPool<MoveTuple>
        > pools;
        std::vector<std::unique_ptr<IEntity>> entities;
        CNetwork network;
    };
}

#endif
