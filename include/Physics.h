#pragma once

#include "Entity.h"
#include "Vec2.h"
#include "Common.h"

class Physics
{
    public:
        
        Vec2 GetOverlap(Entity& a, Entity& b);
        Vec2 GetPreviousOverlap(Entity& a, Entity& b);
        bool IsInside(const Vec2& pos, Entity& e);
        Intersect LineInIntersect(
            const Vec2& a, 
            const Vec2& b, 
            const Vec2& c, 
            const Vec2& d
        );
        bool EntityIntersect(const Vec2& a, const Vec2& b, Entity& e);
        RectOverlap AisNearB(Entity& a, Entity& b, const Vec2& maxDist);
};
