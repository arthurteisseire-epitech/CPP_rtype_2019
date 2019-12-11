/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CCommand.hpp
*/

#ifndef RTYPE_CCOMMAND_HPP
#define RTYPE_CCOMMAND_HPP

#include <vector>
#include "ReceiveProtocole.hpp"

namespace ecs
{
    struct CCommand {
        std::vector<ReceiveProtocole::Key> commands;
    };
}

#endif
