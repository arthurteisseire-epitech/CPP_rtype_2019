/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include "MoveSystem.hpp"
#include "MoveTuple.hpp"
#include "Util.hpp"

ecs::MoveSystem::MoveSystem(std::shared_ptr<EntityAdmin> admin) : ASystem(std::move(admin))
{
}

void ecs::MoveSystem::update(float dt)
{
    ForEachMatching<MoveTuple>(admin, [this](MoveTuple &t) {
        if (get<DirectionComponent>(t).dir != mut::Vec2f({0, 0})) {
            get<TransformComponent>(t).vec += get<DirectionComponent>(t).dir;
            std::cout << "moving by " << get<DirectionComponent>(t).dir.x << ", " << get<DirectionComponent>(t).dir.y << std::endl;
            std::cout << "new pos: " << get<TransformComponent>(t).vec.x << "," << get<TransformComponent>(t).vec.y << std::endl;
            get<DirectionComponent>(t).dir = {0, 0};
        }
    });
}
