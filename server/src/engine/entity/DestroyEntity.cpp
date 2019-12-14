/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** DestroyEntity.cpp
*/

#include "EntityUtil.hpp"
#include "NetworkSender.hpp"
#include "SendProtocol.hpp"
#include "Util.hpp"

void ecs::EntityUtil::DestroyEntity(std::shared_ptr<ecs::EntityAdmin> &admin, unsigned int id)
{
    for (auto &entity: admin->entities)
        if (entity->getId(admin) == id) {
            entity->destroy(admin);
            ForEachMatching<CConnection>(admin, [&admin, &id] (CConnection &conn) {
                NetworkSender::send(admin, conn, Packet(id, std::string(SendProtocol::get(SendProtocol::ENTITY_DESTROY))));
            });
        }
}
