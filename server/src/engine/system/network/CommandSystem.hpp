/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CommandSystem.hpp
*/

#ifndef RTYPE_COMMANDSYSTEM_HPP
#define RTYPE_COMMANDSYSTEM_HPP

#include "ASystem.hpp"

namespace ecs
{
    class CommandSystem : public ASystem {
    public:
        explicit CommandSystem(std::shared_ptr<EntityAdmin> admin);
        void update(float deltaTime) override;

    private:
        static const std::map<std::string, ecs::CCommand::Key> directions;
        static const std::string space;
    };
}

#endif
