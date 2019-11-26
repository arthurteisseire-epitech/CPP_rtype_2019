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
    for (auto &moveComponent : GetPool<MoveTuple>(admin)) {
        if (moveComponent.dir->dir != mut::Vec2f({0, 0})) {
            moveComponent.transform->vec += moveComponent.dir->dir;
            std::cout << "moving by " << moveComponent.dir->dir.x << ", " << moveComponent.dir->dir.y << std::endl;
            std::cout << "new pos: " << moveComponent.transform->vec.x << "," << moveComponent.transform->vec.y << std::endl;
            moveComponent.dir->dir = {0, 0};
        }
    }
}
