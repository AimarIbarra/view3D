#pragma once
#include <cmath>

class Vector3f {
  public:
    Vector3f() noexcept;
    Vector3f(float x, float y, float z) noexcept;
    Vector3f(const Vector3f &vec);

    float getX() noexcept;
    float getY() noexcept;
    float getZ() noexcept;

    void setX(float x) noexcept;
    void setY(float y) noexcept;
    void setZ(float z) noexcept;
    void set(float x, float y, float z) noexcept;

    float length() noexcept;
    Vector3f negate() noexcept;
    Vector3f normalize() noexcept;

    static Vector3f add(Vector3f &vec1, Vector3f &vec2) noexcept;
    static Vector3f sub(Vector3f &vec1, Vector3f &vec2) noexcept;
    static float dot(Vector3f &vec1, Vector3f &vec2) noexcept;
    static Vector3f cross(Vector3f &vec1, Vector3f &vec2) noexcept;
    static Vector3f scaler_mul(Vector3f &vec, float num) noexcept;
    static Vector3f scaler_div(Vector3f &vec, float num);

    Vector3f operator+(Vector3f &vec) noexcept;
    Vector3f operator-(Vector3f &vec) noexcept;
    Vector3f operator*(float num) noexcept;
    Vector3f operator/(float num);

  private:
    float x{}, y{}, z{};
};