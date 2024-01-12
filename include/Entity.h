#pragma once

#include <cstddef>
#include <string>
#include "EntityMemoryPool.h"

class Entity 
{
    size_t m_id;

    public:

    Entity(size_t i);
    const size_t id() const;
    const std::string& tag() const;
    bool isActive() const;
    void destroy();

    template<typename T>
    T& get() {
        return EntityMemoryPool::Instance().get<T>(m_id);
    }

    template<typename T>
    bool has() {
        return EntityMemoryPool::Instance().has<T>(m_id);
    }

    template<typename T, typename... TArgs>
    T& add(TArgs&&... mArgs) {
        auto& component = EntityMemoryPool::Instance().get<T>(m_id);
        component = T(std::forward<TArgs>(mArgs)...);
        component.active = true;
        return component;
    }

    template<typename T>
    void remove() {
        EntityMemoryPool::Instance().get<T>(m_id).active = false;
    }
};
