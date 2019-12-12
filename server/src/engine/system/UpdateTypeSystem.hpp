/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_UPDATETYPESYSTEM_HPP
#define RTYPE_UPDATETYPESYSTEM_HPP

#include "ASystem.hpp"

namespace ecs {
    class UpdateTypeSystem : public ASystem {
    public:
        explicit UpdateTypeSystem(std::shared_ptr<EntityAdmin> admin);

        void update(float dt) override;

    private:
        static const std::unordered_map<std::string_view, std::string_view> nextType;
    };
}

#endif
