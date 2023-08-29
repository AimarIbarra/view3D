#pragma once

class Vector2f {
    public:
    Vector2f() noexcept;
    Vector2f(float x, float y) noexcept;
    Vector2f(const Vector2f &vec);

    float getX() noexcept;
    float getY() noexcept;

    void setX(float x) noexcept;
    void setY(float y) noexcept;

    private:
    float x{}, y{}; 
};