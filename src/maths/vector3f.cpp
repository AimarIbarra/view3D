#include "vector3f.h"

Vector3f::Vector3f() noexcept {}

Vector3f::Vector3f(float x, float y, float z) noexcept {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3f::Vector3f(const Vector3f &vec) {
    this->x = vec.x;
    this->y = vec.y;
    this->z = vec.z;
}

float Vector3f::getX() noexcept { return this->x; }

float Vector3f::getY() noexcept { return this->y; }

float Vector3f::getZ() noexcept { return this->z; }

void Vector3f::setX(float x) noexcept { this->x = x; }

void Vector3f::setY(float y) noexcept { this->y = y; }

void Vector3f::setZ(float z) noexcept { this->z = z; }

void Vector3f::set(float x, float y, float z) noexcept {
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vector3f::length() noexcept {
    return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vector3f Vector3f::negate() noexcept {
    return Vector3f(-this->x, -this->y, -this->z);
}

Vector3f Vector3f::normalize() noexcept {
    float length = this->length();
    return Vector3f(this->x / length, this->y / length, this->z / length);
}

Vector3f Vector3f::add(Vector3f &vec1, Vector3f &vec2) noexcept {
    return Vector3f(vec1.getX() + vec2.getX(), vec1.getY() + vec2.getY(),
                    vec1.getZ() + vec2.getZ());
}

Vector3f Vector3f::sub(Vector3f &vec1, Vector3f &vec2) noexcept {
    return Vector3f(vec1.getX() - vec2.getX(), vec1.getY() - vec2.getY(),
                    vec1.getZ() - vec1.getZ());
}

float Vector3f::dot(Vector3f &vec1, Vector3f &vec2) noexcept {
    return vec1.getX() * vec1.getX() + vec1.getY() * vec2.getY() + vec1.getZ() +
           vec2.getZ();
}

Vector3f Vector3f::cross(Vector3f &vec1, Vector3f &vec2) noexcept {
    return Vector3f(vec1.y * vec2.z - vec1.z * vec2.y,
                    vec1.z * vec2.x - vec1.x * vec2.z,
                    vec1.x * vec2.y - vec1.y * vec2.x);
}

Vector3f Vector3f::scaler_mul(Vector3f &vec, float num) noexcept {
    return Vector3f(vec.x * num, vec.y * num, vec.z * num);
}

Vector3f Vector3f::scaler_div(Vector3f &vec, float num) {
    return Vector3f(vec.x / num, vec.y / num, vec.z / num);
}

Vector3f Vector3f::operator+(Vector3f &vec) noexcept {
    return Vector3f::add(*this, vec);
}

Vector3f Vector3f::operator-(Vector3f &vec) noexcept {
    return Vector3f::sub(*this, vec);
}

Vector3f Vector3f::operator*(float num) noexcept {
    return Vector3f::scaler_mul(*this, num);
}

Vector3f Vector3f::operator/(float num) {
    return Vector3f::scaler_div(*this, num);
}
