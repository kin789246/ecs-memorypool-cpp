#include "EntityManager.h"
#include <vector>

EntityManager::EntityManager() {};

Entity EntityManager::addEntity(const std::string& tag)
{
    size_t id = EntityMemoryPool::Instance().addEntity(tag);
    Entity e(id);
    m_entitiesToAdd.push_back(e);
    return e;
}

void EntityManager::update() {
    // add entities from m_entitiesToAdd the proper location(s) 
    for (auto e : m_entitiesToAdd) {
        m_entities.push_back(e);
    }
    m_entitiesToAdd.clear();

    // remove dead entities from the vector of all entities
    std::erase_if(
        m_entities, 
        [] (Entity e) { 
            return !e.isActive(); 
        }
    );
}

std::vector<Entity> EntityManager::getEntities() {
    return m_entities;
}

std::vector<Entity> EntityManager::getEntities(const std::string& tag) {
    std::vector<Entity> entities;
    for (auto &e : m_entities) {
        if (EntityMemoryPool::Instance().getEntitiles(e.id(), tag)) {
            entities.push_back(e);
        }
    }

    return entities;
}
