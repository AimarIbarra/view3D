#ifndef MATRIX_H
#define MATRIX_H

#include <array>
#include <initializer_list>

template <typename FloatT, std::size_t x, std::size_t y = x>
struct Matrix {
    std::array<std::array<FloatT, y>, x> _mat;

    using Type = Matrix<FloatT, x, y>;

    std::array<FloatT, y> &operator[](std::size_t index) noexcept {
        return _mat[index];
    }

    const std::array<FloatT, y> &operator[](std::size_t index) const noexcept {
        return _mat[index];
    }
  
    Type operator+(const Type &other) const noexcept {
        Type res = *this;
        for (std::size_t i = 0; i < x; ++i) {
            for (std::size_t j = 0; j < y; ++j) {
                res[i][j] += other[i][j];
            }
        }
        return res;
    }
  
    Type operator-(const Type &other) const noexcept {
        Type res = *this;
        for (std::size_t i = 0; i < x; ++i) {
            for (std::size_t j = 0; j < y; ++j) {
                res[i][j] -= other[i][j];
            }
        }
        return res;
    }

    template <std::size_t ox>
    Matrix<FloatT, ox, y> operator*(const Matrix<FloatT, ox, x> &other)
      const noexcept {
        Matrix<FloatT, ox, y> res{};
        // TODO: This multiplication loop is not cache friendly!
        for (std::size_t i = 0; i < ox; ++i) {
            for (std::size_t j = 0; j < y; ++j) {
                for (std::size_t k = 0; k < x; ++k) {
                    res[i][j] += _mat[k][j] * other[i][k];
                }
            }
        }
        return res;
    }
  
    Type operator*(const FloatT &num) noexcept {
        Type res = *this;
        for (std::size_t i = 0; i < x; ++i) {
            for (std::size_t j = 0; j < y; ++j) {
                res[i][j] *= num;
            }
        }
        return res;
    }
  
    Type operator/(const FloatT &num) noexcept {
        Type res = *this;
        for (std::size_t i = 0; i < x; ++i) {
            for (std::size_t j = 0; j < y; ++j) {
                res[i][j] /= num;
            }
        }
        return res;
    }
};

template <std::size_t x, std::size_t y = x>
using Matrixf = Matrix<float, x, y>;

template <std::size_t x, std::size_t y = x>
using Matrixd = Matrix<double, x, y>;

#endif
