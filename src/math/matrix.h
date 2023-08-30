#ifndef MATRIX_H
#define MATRIX_H

#include <array>
#include <initializer_list>

struct Matrix {
    std::array<std::array<float, 4>, 4> _mat;

    std::array<float, 4> &operator[](std::size_t index) noexcept {
        return _mat[index];
    }

    const std::array<float, 4> &operator[](std::size_t index) const noexcept {
        return _mat[index];
    }

    Matrix operator+(const Matrix &other) const noexcept {
        Matrix res = *this;
        for (std::size_t i = 0; i < 4; ++i) {
            for (std::size_t j = 0; j < 4; ++j) {
                res[i][j] += other[i][j];
            }
        }
        return res;
    }

    Matrix operator-(const Matrix &other) const noexcept {
        Matrix res = *this;
        for (std::size_t i = 0; i < 4; ++i) {
            for (std::size_t j = 0; j < 4; ++j) {
                res[i][j] -= other[i][j];
            }
        }
        return res;
    }

    Matrix operator*(const Matrix &other) const noexcept {
        Matrix res{};
        // TODO: This multiplication loop is not cache friendly!
        for (std::size_t i = 0; i < 4; ++i) {
            for (std::size_t j = 0; j < 4; ++j) {
                for (std::size_t k = 0; k < 4; ++k) {
                    res[i][j] += _mat[k][j] * other[i][k];
                }
            }
        }
        return res;
    }

    Matrix operator*(const float &num) noexcept {
        Matrix res = *this;
        for (std::size_t i = 0; i < 4; ++i) {
            for (std::size_t j = 0; j < 4; ++j) {
                res[i][j] *= num;
            }
        }
        return res;
    }

    Matrix operator/(const float &num) noexcept {
        Matrix res = *this;
        for (std::size_t i = 0; i < 4; ++i) {
            for (std::size_t j = 0; j < 4; ++j) {
                res[i][j] /= num;
            }
        }
        return res;
    }
};

#endif
