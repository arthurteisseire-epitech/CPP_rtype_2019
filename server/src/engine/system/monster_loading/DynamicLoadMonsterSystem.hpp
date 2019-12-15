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
#include "LibraryLoader.hpp"

namespace ecs
{
    class DynamicLoadMonsterSystem : public ASystem {
    public:
        explicit DynamicLoadMonsterSystem(std::shared_ptr<EntityAdmin>);
        void update(float dTime) override;

        static std::vector<std::unique_ptr<AMonster>> monsterLibs;
    private:
        const std::regex loadLibRegex;
        std::vector<LibraryLoader> loadedLibs;
        std::vector<std::string> loadedLibsName;

        bool loadLibrary(const std::string &toLoad);
    };
}

#endif
