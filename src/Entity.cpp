#include "Entity.h"

Entity::Entity(size_t i) : m_id(i) {}

const size_t Entity::id() const {
    return m_id;
}

void Entity::destroy() {
    EntityMemoryPool::Instance().destroy(m_id);
}

bool Entity::isActive() const {
    return EntityMemoryPool::Instance().isActive(m_id);
}

const std::string& Entity::tag() const {
    return EntityMemoryPool::Instance().getTag(m_id);
}
