/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** DirectionUpdateSystem.cpp
*/

#include <random>
#include "DirectionUpdateSystem.hpp"
#include "DirectionUpdateTuple.hpp"

ecs::DirectionUpdateSystem::DirectionUpdateSystem(std::shared_ptr<EntityAdmin> admin) :
    ASystem(admin),
    moveUpdate(initMap())
{
}

std::map<ecs::CMoveType::MOVE_TYPE, std::function<void(ecs::CDirection &)>> ecs::DirectionUpdateSystem::initMap()
{
    return {
        {CMoveType::STRAIGHT, [](CDirection &) {}},
        {CMoveType::NONE, [](CDirection &) {}},
        {CMoveType::RANDOM, [](CDirection &dir) {
            dir.setDirection(CDirection::Direction(std::rand() % CDirection::LAST));
        }},
        {CMoveType::SIN, [this](CDirection &dir) {
            if (dir.dir == CDirection::LEFT) {
                if (std::rand() % 2 == 0)
                    dir.setDirection(CDirection::UP);
                else
                    dir.setDirection(CDirection::DOWN);
            } else
                dir.setDirection(CDirection::LEFT);
        }}
    };
};

void ecs::DirectionUpdateSystem::update(float dTime)
{
    ForEachMatching<DirectionUpdateTuple>(admin, [this](DirectionUpdateTuple &t) {
        moveUpdate.at(get<CMoveType>(t).type)(get<CDirection>(t));
    });
}
