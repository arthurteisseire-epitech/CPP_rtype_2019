/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include "LibraryLoader.hpp"
#include "DynamicLoadMonsterSystem.hpp"
#include "MonsterTuple.hpp"
#include "EntityFactory.hpp"

ecs::DynamicLoadMonsterSystem::DynamicLoadMonsterSystem(std::shared_ptr<EntityAdmin> admin) :
    ASystem(admin),
    loadLibRegex("^load (.+?.so)$")
{
    loadLibrary("../lib/librandom_monster.so");
}

std::vector<std::unique_ptr<ecs::AMonster>> ecs::DynamicLoadMonsterSystem::monsterLibs = {};

void ecs::DynamicLoadMonsterSystem::update(float)
{
    std::string line;
    std::smatch match;

    while (std::getline(std::cin, line)) {
        if (std::regex_match(line, match, loadLibRegex) && std::find(loadedLibsName.begin(), loadedLibsName.end(), match[1]) == loadedLibsName.end()) {
            std::string toLoad = match[1];
            std::cout << "matched: " << toLoad << std::endl;
            loadLibrary(toLoad);
        } else
            std::cout << "unknown command" << std::endl;
    }
}

bool ecs::DynamicLoadMonsterSystem::loadLibrary(const std::string &toLoad)
{
    LibraryLoader lib;
    try {
        monsterLibs.emplace_back(lib.loadInstance<ecs::AMonster>(toLoad, "monsterEntryPoint"));
        loadedLibs.emplace_back(lib);
        loadedLibsName.emplace_back(toLoad);
        return true;
    } catch (LibraryLoaderException &exception) {
        std::cerr << exception.what() << std::endl;
        return false;
    }
}
