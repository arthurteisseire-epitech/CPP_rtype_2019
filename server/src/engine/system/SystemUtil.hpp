/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SystemUtil.hpp
*/

#ifndef RTYPE_SYSTEMUTIL_HPP
#define RTYPE_SYSTEMUTIL_HPP

#include <vector>
#include "ASystem.hpp"

namespace ecs
{
    class SystemsUtil {
    public:
        static std::vector<std::unique_ptr<ASystem>> Init(std::shared_ptr<EntityAdmin> &admin);
        static void Update(std::vector<std::unique_ptr<ecs::ASystem>> &systems, float deltaTime);
    };
}

#endif
