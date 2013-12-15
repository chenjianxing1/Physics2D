#include "Circle.hpp"

#include "AxisAlignedBox.hpp"
#include "OrientedBox.hpp"

Circle::Circle() :
    Collision(Collision::CIRCLE),
    radius(0),
    color(0, 0, 0)
{
}

Circle::Circle(const CGUL::Vector2& position, CGUL::Float32 radius) :
    Collision(Collision::CIRCLE),
    position(position),
    radius(radius),
    color(0, 0, 0)
{
}

void Circle::SetPosition(const CGUL::Vector2& position)
{
    this->position = position;
}

void Circle::SetRadius(CGUL::Float32 radius)
{
    this->radius = radius;
}

CGUL::Vector2 Circle::GetPosition() const
{
    return position;
}

CGUL::Float32 Circle::GetRadius() const
{
    return radius;
}

void Circle::ProjectionOnAxis(const CGUL::Vector2& axis, CGUL::Float32* min, CGUL::Float32* max) const
{
    CGUL::Float32 projection = CGUL::Vector2::DotProduct(axis, position);
    *min = projection - radius;
    *max = projection - radius;
}

bool Circle::CollidingCircle(const Circle& other) const
{
    return CheckCircleAndCircle(*this, other);
}

bool Circle::CollidingAxisAlignedBox(const AxisAlignedBox& other) const
{
    return false;
}

bool Circle::CollidingOrientedBox(const OrientedBox& other) const
{
    return false;
}

void Circle::Draw() const
{
    render->Circle(position, radius, color);
}