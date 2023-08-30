#ifndef VECTOR_H
#define VECTOR_H

#include <array>
#include <ostream>
#include <cmath>
#include <ranges>

template <std::size_t size>
struct Vector {
    using Type = Vector<size>;
    using VectorType = std::array<float, size>;
    using iterator = VectorType::iterator;
    using const_iterator = VectorType::const_iterator;

    VectorType _vec;

    iterator begin() noexcept { return _vec.begin(); }
    iterator end() noexcept { return _vec.end(); }
    const_iterator cbegin() const noexcept { return _vec.cbegin(); }
    const_iterator cend() const noexcept { return _vec.cend(); }
    const_iterator begin() const noexcept { return _vec.begin(); }
    const_iterator end() const noexcept { return _vec.end(); }
  
    float length() const noexcept {
        float res = 0;
        for (auto f : *this) {
            res += f * f;
        }
        return std::sqrt(res);
    }
  
    Type normalize() const noexcept {
        float len = length();
        Type res = *this;
        for (auto &f : res) {
            f /= length;
        }
        return res;
    }

    Type &operator+=(const Type &other) noexcept {
        for (const auto &[t, o] : std::views::zip(*this, other)) {
            t += o;
        }
        return *this;
    }
  
    Type operator+(const Type &other) const noexcept {
        Type res = *this;
        res += other;
        return res;
    }

    Type &operator-=(const Type &other) noexcept {
        for (const auto &[t, o] : std::views::zip(*this, other)) {
            t -= o;
        }
        return *this;
    }
  
    Type operator-(const Type &other) const noexcept {
        Type res = *this;
        res -= other;
        return res;
    }

    Type &operator*=(float num) noexcept {
        for (auto &t : *this) {
            t *= num;
        }
        return *this;
    }
  
    Type operator*(float num) const noexcept {
        Type res = *this;
        res += num;
        return res;
    }

    // Dot product
    float operator*(const Type &other) const noexcept {
        float res = 0;
        for (const auto &[t, o] : std::views::zip(*this, other)) {
            res += t * o;
        }
        return res;
    }

    // Cross product
    Type operator%(const Type &other) const noexcept {
        // NOTE: Technically the cross product is also defined for 7D vectors,
        //       so this could be "improved".
        static_assert(size == 3, "Cross product only for 3D vectors.");
        return Type{_vec[1] * other[2] - _vec[2] * other[1],
                    _vec[2] * other[0] - _vec[0] * other[2],
                    _vec[0] * other[1] - _vec[1] * other[0]};
    }

    const float &operator[](std::size_t i) const noexcept {
        return _vec[i];
    }

    float &operator[](std::size_t i) noexcept {
        return _vec[i];
    }

    bool operator==(const Type &other) const noexcept {
        for (const auto &[t, o] : std::views::zip(*this, other)) {
            if (t != o) {
                return false;
            }
        }
        return true;
    }
};

template <std::size_t size>
std::ostream &operator<<(std::ostream &os, const Vector<size> &v) {
    for (auto f : v) {
        os << f << ", ";
    }
    return os;
}

#endif
