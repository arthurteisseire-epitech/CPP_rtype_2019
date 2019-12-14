/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#include <istream>
#include "DynamicLoadMonsterSystem.hpp"
#include "MonsterTuple.hpp"
#include "EntityFactory.hpp"
#include "BasicMonster.hpp"

ecs::DynamicLoadMonsterSystem::DynamicLoadMonsterSystem(std::shared_ptr<EntityAdmin> admin) :
    ASystem(admin),
//    loadLibRegex("^load (((/?[^/ ]*)+/?)|(([a-zA-Z]:)?(\\?[a-z  A-Z0-9_.-]+)+))$")
    loadLibRegex("^load (basic)$")
{
}

// TODO: remove and replace with dynamic loading
std::map<std::string, std::function<std::unique_ptr<ecs::AMonster>()>> ecs::DynamicLoadMonsterSystem::monsterFactory = {
    {"basic", []() {return std::make_unique<BasicMonster>();}}
};

std::vector<std::unique_ptr<ecs::AMonster>> ecs::DynamicLoadMonsterSystem::monsterLibs = {};

std::vector<std::string> ecs::DynamicLoadMonsterSystem::loadedLibs = {};


void ecs::DynamicLoadMonsterSystem::update(float dTime)
{
    std::string line;
    std::smatch match;

    while (std::getline(std::cin, line)) {
        if (std::regex_match(line, match, loadLibRegex) && std::find(loadedLibs.begin(), loadedLibs.end(), match[1]) == loadedLibs.end()) {
            std::cout << "matched: " << match[1] << std::endl;
            monsterLibs.emplace_back(monsterFactory.at(match[1])());
            loadedLibs.emplace_back(match[1]);
        } else
            std::cout << "unknown command" << std::endl;
    }
}
