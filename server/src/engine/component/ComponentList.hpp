/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ComponentList.hpp
*/

#ifndef RTYPE_COMPONENTLIST_HPP
#define RTYPE_COMPONENTLIST_HPP

#include <tuple>
#include "CConnection.hpp"
#include "CDirection.hpp"
#include "CId.hpp"
#include "CCommand.hpp"
#include "CTransform.hpp"
#include "CType.hpp"

namespace ecs
{
    using ComponentList = std::tuple
        <
            CConnection,
            CDirection,
            CId,
            CCommand,
            CTransform,
            CType
        >;
}

#endif
