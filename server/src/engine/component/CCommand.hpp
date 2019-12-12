/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CCommand.hpp
*/

#ifndef RTYPE_CCOMMAND_HPP
#define RTYPE_CCOMMAND_HPP

#include <vector>
#include "ReceiveProtocol.hpp"

namespace ecs
{
    struct CCommand {
        std::vector<std::pair<ReceiveProtocol::Key, std::string>> commands;
    };
}

#endif
