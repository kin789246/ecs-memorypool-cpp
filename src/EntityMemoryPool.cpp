#include "EntityMemoryPool.h"
#include <iostream>
#include <tuple>

EntityMemoryPool::EntityMemoryPool(size_t maxEntities) : m_numEntities(0) {
    for (size_t i=0; i<maxEntities; i++) {
        m_tags.push_back("");
        m_actives.push_back(false);
    }
    m_pool = std::make_tuple(
        std::vector<CTransform>(maxEntities),
        std::vector<CLifespan>(maxEntities),
        std::vector<CDamage>(maxEntities),
        std::vector<CInvicibility>(maxEntities),
        std::vector<CHealth>(maxEntities),
        std::vector<CInput>(maxEntities),
        std::vector<CBoundingBox>(maxEntities),
        std::vector<CAnimation>(maxEntities),
        std::vector<CGravity>(maxEntities),
        std::vector<CState>(maxEntities),
        std::vector<CFollowPlayer>(maxEntities),
        std::vector<CPatrol>(maxEntities),
        std::vector<CDraggable>(maxEntities)
    );
}

size_t EntityMemoryPool::addEntity(const std::string& tag) {
    size_t index = getNextEntityIndex();
    if (index == MAX_ENTITIES) {
        std::cerr << "Entity Memory Pool is full!\n";
        exit(-1);
    }
    m_tags[index] = tag;
    m_actives[index] = true;

    std::get<std::vector<CTransform>>(m_pool)[index].active = false;
    std::get<std::vector<CLifespan>>(m_pool)[index].active = false;
    std::get<std::vector<CDamage>>(m_pool)[index].active = false;
    std::get<std::vector<CInvicibility>>(m_pool)[index].active = false;
    std::get<std::vector<CHealth>>(m_pool)[index].active = false;
    std::get<std::vector<CInput>>(m_pool)[index].active = false;
    std::get<std::vector<CBoundingBox>>(m_pool)[index].active = false;
    std::get<std::vector<CAnimation>>(m_pool)[index].active = false;
    std::get<std::vector<CGravity>>(m_pool)[index].active = false;
    std::get<std::vector<CState>>(m_pool)[index].active = false;
    std::get<std::vector<CFollowPlayer>>(m_pool)[index].active = false;
    std::get<std::vector<CPatrol>>(m_pool)[index].active = false;
    std::get<std::vector<CDraggable>>(m_pool)[index].active = false;

    m_numEntities++;
    return index;
}
bool EntityMemoryPool::getEntitiles(size_t id, const std::string& tag) {
    return m_actives[id] && (m_tags[id] == tag);
}

const std::string& EntityMemoryPool::getTag(size_t id) {
    return m_tags[id];
}

void EntityMemoryPool::destroy(size_t id) {
    m_actives[id] = false;
    m_numEntities--;
}

bool EntityMemoryPool::isActive(size_t id) {
    if (id >= MAX_ENTITIES) {
        return false;
    }
    return m_actives[id];
}

size_t EntityMemoryPool::getNextEntityIndex() {
    for (size_t i=0; i<m_actives.size(); i++) {
        if (m_actives[i] == false) {
            return i;
        }
    }
    return MAX_ENTITIES;
}
