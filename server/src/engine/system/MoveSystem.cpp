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
        if (get<CDirection>(t).dir != mut::Vec2f({0, 0})) {
            get<CTransform>(t).vec += get<CDirection>(t).dir;
            std::cout << "moving by " << get<CDirection>(t).dir.x << ", " << get<CDirection>(t).dir.y << std::endl;
            std::cout << "new pos: " << get<CTransform>(t).vec.x << "," << get<CTransform>(t).vec.y << std::endl;
            if (!get<CDirection>(t).keepMovement)
                get<CDirection>(t).dir = {0, 0};
        }
    });
}
