/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CommandDirectionSystem.hpp
*/

#ifndef RTYPE_COMMANDDIRECTIONSYSTEM_HPP
#define RTYPE_COMMANDDIRECTIONSYSTEM_HPP

#include "ASystem.hpp"

namespace ecs
{
    class CommandDirectionSystem : public ASystem {
    public:
        explicit CommandDirectionSystem(std::shared_ptr<EntityAdmin> admin);

        void update(float dt) override;

    private:
        static bool isKeyADirection(const std::pair<ReceiveProtocol::Key, std::string> &pair);
        static const std::map<ReceiveProtocol::Key, ecs::CDirection::Direction> directions;
    };
}

#endif
