/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_DYNAMICLOADMONSTERSYSTEM_HPP
#define RTYPE_DYNAMICLOADMONSTERSYSTEM_HPP

#include <regex>
#include "ASystem.hpp"
#include "AMonster.hpp"

namespace ecs
{
    class DynamicLoadMonsterSystem : public ASystem {
    public:
        explicit DynamicLoadMonsterSystem(std::shared_ptr<EntityAdmin>);
        void update(float dTime) override;

        static std::vector<std::unique_ptr<AMonster>> monsterLibs;
    private:
        const std::regex loadLibRegex;

        static std::vector<std::string> loadedLibs;
        static std::map<std::string, std::function<std::unique_ptr<AMonster>()>> monsterFactory;
    };
}

#endif
