/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** EntityAdmin.hpp
*/

#ifndef RTYPE_ENTITYADMIN_HPP
#define RTYPE_ENTITYADMIN_HPP

#include <tuple>
#include "TupleTypeUtil.hpp"
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

        Pools pools{};
        std::vector<std::unique_ptr<IEntity>> entities;
        CNetwork network;
    };
}

#endif
