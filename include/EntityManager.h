#pragma once

#include "Entity.h"
#include <vector>
class EntityManager
{
    std::vector<Entity> m_entities;
    std::vector<Entity> m_entitiesToAdd; // entities to add next update
                              
    public:

    EntityManager();
    Entity addEntity(const std::string& tag);
    void update();

    std::vector<Entity> getEntities();
    std::vector<Entity> getEntities(const std::string& tag);
};
