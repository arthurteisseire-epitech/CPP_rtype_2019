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
    auto &transformPool = GetPool<TransformComponent>(admin);
    auto &dirPool = GetPool<DirectionComponent>(admin);

    for (auto &t : GetPool<MoveTuple>(admin)) {
        auto &dir = dirPool.at(t.directionIdx);
        auto &transform = transformPool.at(t.transformIdx);

        if (dir.dir != mut::Vec2f({0, 0})) {
            transform.vec += dir.dir;
            std::cout << "moving by " << dir.dir.x << ", " << dir.dir.y << std::endl;
            std::cout << "new pos: " << transform.vec.x << "," << transform.vec.y << std::endl;
            dir.dir = {0, 0};
        }
    }

}
