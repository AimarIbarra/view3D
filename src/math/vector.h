#ifndef VECTOR_H
#define VECTOR_H

#include <array>
#include <initializer_list>
#include <cmath>

template <typename FloatT, std::size_t len>
struct Vector {
    std::array<FloatT, len> _vec;

    using Type = Vector<FloatT, len>;

    FloatT length() const noexcept {
        FloatT res = 0;
        for (const auto &f : _vec) {
            res += f * f;
        }
        return std::sqrt(res);
    }
  
    Type normalize() const noexcept {
        FloatT length = length();
        Type res = *this;
        for (auto &f : res._vec) {
            f /= length;
        }
        return res;
    }

    Type operator+(const Type &other) const noexcept {
        Type res = *this;
        for (std::size_t i = 0; i < len; ++i) {
            res[i] += other[i];
        }
        return res;
    }
  
    Type operator-(const Type &other) const noexcept {
        Type res = *this;
        for (std::size_t i = 0; i < len; ++i) {
            res[i] -= other[i];
        }
        return res;
    }

    Type operator*(const FloatT &num) const noexcept {
        Type res = *this;
        for (auto &f : res._vec) {
            f += num;
        }
        return res;
    }

    // Dot product
    FloatT operator*(const Type &other) const noexcept {
        FloatT res = 0;
        for (std::size_t i = 0; i < len; ++i) {
            res += _vec[i] * other._vec[i];
        }
        return res;
    }

    // Cross product
    Type operator%(const Type &other) const noexcept {
        // NOTE: Technically the cross product is also defined for 7D vectors,
        //       so this could be "improved".
        static_assert(len == 3, "Cross product only defined for 3D vectors.");
        return Type{_vec[1] * other[2] - _vec[2] * other[1],
                    _vec[2] * other[0] - _vec[0] * other[2],
                    _vec[0] * other[1] - _vec[1] * other[0]};
    }

    const FloatT &operator[](std::size_t i) const noexcept {
        return _vec[i];
    }

    FloatT &operator[](std::size_t i) noexcept {
        return _vec[i];
    }
};

template <std::size_t len>
using Vectorf = Vector<float, len>;

template <std::size_t len>
using Vectord = Vector<double, len>;

#endif
