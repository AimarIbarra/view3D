#ifndef MATRIX_H
#define MATRIX_H

#include <array>

struct Matrix {
    using MatrixType = std::array<float, 4*4>;
    using iterator = MatrixType::iterator;
    using const_iterator = MatrixType::const_iterator;
  
    MatrixType _mat;

    iterator begin() noexcept;
    iterator end() noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;
    const_iterator begin() const noexcept;
    const_iterator end() const noexcept;

    struct AccessProxy {
        float *_ptr;
        float &operator[](std::size_t index) noexcept;
    };
    AccessProxy operator[](std::size_t index) noexcept;

    struct ConstAccessProxy {
        const float *_ptr;
        float operator[](std::size_t index) const noexcept;
    };
    ConstAccessProxy operator[](std::size_t index) const noexcept;

    Matrix &operator+=(const Matrix &other) noexcept;
    Matrix operator+(const Matrix &other) const noexcept;
    Matrix &operator-=(const Matrix &other) noexcept;
    Matrix operator-(const Matrix &other) const noexcept;
    Matrix operator*(const Matrix &other) const noexcept;
    Matrix &operator*=(float num) noexcept;
    Matrix operator*(float num) const noexcept;
    Matrix &operator/=(float num) noexcept;
    Matrix operator/(float num) const noexcept;
    bool operator==(const Matrix &other) const noexcept;
};

#endif
