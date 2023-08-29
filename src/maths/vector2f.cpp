#include "vector2f.h"

Vector2f::Vector2f() noexcept {}

Vector2f::Vector2f(float x, float y) noexcept
{
    this->x = x;
    this->y = y;
}

Vector2f::Vector2f(const Vector2f &vec)
{
    this->x = vec.x;
    this->y = vec.y;
}

float Vector2f::getX() noexcept
{
    return this->x;
}

float Vector2f::getY() noexcept
{
    return this->y;
}

void Vector2f::setX(float x) noexcept
{
    this->x = x;
}

void Vector2f::setY(float y) noexcept
{
    this->y = y;
}
