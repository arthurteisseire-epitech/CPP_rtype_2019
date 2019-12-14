/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** DirectionUpdateSystem.hpp
*/

#ifndef RTYPE_DIRECTIONUPDATESYSTEM_HPP
#define RTYPE_DIRECTIONUPDATESYSTEM_HPP

#include <map>
#include "ASystem.hpp"
#include "CMoveType.hpp"

namespace ecs
{
    class DirectionUpdateSystem : public ASystem {
    public:
        explicit DirectionUpdateSystem(std::shared_ptr<EntityAdmin> admin);
        void update(float dTime);

    private:
        std::map<CMoveType::MOVE_TYPE, std::function<void(CDirection &)>> initMap();
        std::map<CMoveType::MOVE_TYPE, std::function<void(CDirection &)>> moveUpdate;
    };
}

#endif
