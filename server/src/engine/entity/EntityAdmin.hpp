/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** EntityAdmin.hpp
*/

#ifndef RTYPE_ENTITYADMIN_HPP
#define RTYPE_ENTITYADMIN_HPP

#include <tuple>
#include "ObjectPool.hpp"
#include "IEntity.hpp"

#include "CNetwork.hpp"

#include "CreationBulletTuple.hpp"
#include "SendRenderTuple.hpp"
#include "MoveTuple.hpp"
#include "InputTuple.hpp"
#include "InputDirectionTuple.hpp"

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
            ObjectPool<CInput>,

            ObjectPool<InputTuple>,
            ObjectPool<SendRenderTuple>,
            ObjectPool<MoveTuple>,
            ObjectPool<CreationBulletTuple>,
            ObjectPool<InputDirectionTuple>
        > pools{};
        std::vector<std::unique_ptr<IEntity>> entities;
        CNetwork network;
    };
}

#endif
