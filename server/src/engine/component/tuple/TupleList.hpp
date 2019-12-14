/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** TupleList.hpp
*/

#ifndef RTYPE_TUPLELIST_HPP
#define RTYPE_TUPLELIST_HPP

#include "MoveTuple.hpp"
#include "CommandTuple.hpp"
#include "SendRenderTuple.hpp"
#include "CreationBulletTuple.hpp"
#include "CommandDirectionTuple.hpp"
#include "HandleConnectionTuple.hpp"
#include "ShootingAITuple.hpp"
#include "CollisionTuple.hpp"
#include "DestroyOOBTuple.hpp"
#include "NotifyPlayerTuple.hpp"

namespace ecs
{
    using TupleList = std::tuple
        <
            MoveTuple,
            CommandTuple,
            SendTuple,
            CreationBulletTuple,
            InputDirectionTuple,
            HandleConnectionTuple,
            ShootingAITuple,
            CollisionTuple,
            DestroyOOBTuple,
            NotifyPlayerTuple
        >;
}

#endif
