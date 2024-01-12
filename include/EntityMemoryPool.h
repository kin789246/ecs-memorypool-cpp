#pragma once

#include "Components.h"
#include <string>

#define MAX_ENTITIES 10000

typedef std::tuple<
    std::vector<CTransform>,
    std::vector<CLifespan>,
    std::vector<CDamage>,
    std::vector<CInvicibility>,
    std::vector<CHealth>,
    std::vector<CInput>,
    std::vector<CBoundingBox>,
    std::vector<CAnimation>,
    std::vector<CGravity>,
    std::vector<CState>,
    std::vector<CFollowPlayer>,
    std::vector<CPatrol>,
    std::vector<CDraggable>
> EntityComponentVectorTuple;

class EntityMemoryPool
{
    size_t m_numEntities;
    EntityComponentVectorTuple m_pool;
    std::vector<std::string> m_tags;
    std::vector<bool> m_actives;

    EntityMemoryPool(size_t maxEntities);
    size_t getNextEntityIndex();

    public:

    static EntityMemoryPool& Instance() {
        static EntityMemoryPool pool(MAX_ENTITIES);
        return pool;
    }

    size_t addEntity(const std::string& tag);
    bool getEntitiles(size_t id, const std::string& tag);
    const std::string& getTag(size_t id);
    void destroy(size_t id);
    bool isActive(size_t id);

    template<typename T>
    bool has(size_t entityID) {
        return std::get<std::vector<T>>(m_pool)[entityID].active;
    }

    template<typename T>
    T& get(size_t entityID) {
        return std::get<std::vector<T>>(m_pool)[entityID];
    }

    const std::string& getTag(size_t entityID) const {
        return m_tags[entityID];
    }
};
