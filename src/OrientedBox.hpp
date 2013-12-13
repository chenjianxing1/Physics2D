#pragma once
#include <CGUL.hpp>
#include "Collision.hpp"
#include "Render.hpp"

extern Render* render;

struct OrientedBox : public Collision
{
    CGUL::Color color;
    CGUL::Vector2 position;
    CGUL::Vector2 halfExtents;
    CGUL::Float32 orientation;

    OrientedBox();
    OrientedBox(const CGUL::Vector2& position, const CGUL::Vector2& halfExtents, CGUL::Float32 orientation);

    void SetPosition(const CGUL::Vector2& position);
    void SetHalfExtents(const CGUL::Vector2& halfExtents);
    void SetOrientation(CGUL::Float32 orientation);

    CGUL::Vector2 GetPosition() const;
    CGUL::Vector2 GetHalfExtents() const;
    CGUL::Float32 GetOrientation() const;

    void ProjectionOnAxis(const CGUL::Vector2& axis, CGUL::Float32* min, CGUL::Float32* max) const;

    bool CollidingAxisAlignedBox(const AxisAlignedBox& other) const;
    bool CollidingOrientedBox(const OrientedBox& other) const;

    void Draw() const;
};