/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ConnectionSystem.cpp
*/

#include "Network.hpp"
#include "ConnectionSystem.hpp"

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

void ecs::ConnectionSystem::update(float deltaTime, ecs::EntityAdmin &admin)
{
    net::Network<Functor> network(1234, std::make_shared<Functor>());
}
