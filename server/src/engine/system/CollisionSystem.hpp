/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** CollisionSystem.hpp
*/

#ifndef RTYPE_COLLISIONSYSTEM_HPP
#define RTYPE_COLLISIONSYSTEM_HPP

#include "ASystem.hpp"
#include "CollisionTuple.hpp"

namespace ecs
{
    class CollisionSystem : public ASystem {
    public:
        explicit CollisionSystem(std::shared_ptr<EntityAdmin> admin);

        void update(float dt) override;
        void updateTuple(CCommand &t);

    private:
        void handleCollision(const std::pair<ReceiveProtocol::Key, std::string> &command);
        static bool isCollision(const std::pair<ReceiveProtocol::Key, std::string> &pair);
    };
}

#endif
