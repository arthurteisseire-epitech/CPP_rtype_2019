/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** main.cpp
*/

#include <iostream>
#include "Network.hpp"
#include "EntityManager.hpp"
#include "IComponent.hpp"
#include "HealthComponent.hpp"
#include "TransformComponent.hpp"

class Functor {
public:
    bool operator()(const std::array<char, BUFFER_SIZE> &request, std::array<char, BUFFER_SIZE> &response)
    {
        for (auto &c : request)
            std::cout << c;
        std::cout << std::endl;
        std::copy(request.begin(), request.end(), response.begin());
        return false;
    }
};

int main()
{
    //    net::Network<Functor> network(1234, std::make_shared<Functor>());
    ecs::EntityManager entityManager;

    std::vector<std::unique_ptr<ecs::IComponent>> a;
    a.reserve(2);
    a.emplace_back(new ecs::HealthComponent);
    a.emplace_back(new ecs::TransformComponent);

    entityManager.createEntity<ecs::HealthComponent, ecs::TransformComponent>();
}
