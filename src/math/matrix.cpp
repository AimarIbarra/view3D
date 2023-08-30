#include <matrix.h>
#include <ranges>
#include <ostream>

namespace sv = std::views;
using Mat = Matrix;

Mat::iterator Mat::begin() noexcept { return _mat.begin(); }
Mat::iterator Mat::end() noexcept { return _mat.end(); }
Mat::const_iterator Mat::cbegin() const noexcept { return _mat.cbegin(); }
Mat::const_iterator Mat::cend() const noexcept { return _mat.cend(); }
Mat::const_iterator Mat::begin() const noexcept { return _mat.begin(); }
Mat::const_iterator Mat::end() const noexcept { return _mat.end(); }

float &Mat::AccessProxy::operator[](std::size_t index) noexcept {
    return _ptr[index*4];
}

Mat::AccessProxy Mat::operator[](std::size_t index) noexcept {
    return AccessProxy{&_mat[index]};
}

float Mat::ConstAccessProxy::operator[](std::size_t index) const noexcept {
    return _ptr[index*4];
}

Mat::ConstAccessProxy Mat::operator[](std::size_t index) const noexcept {
    return ConstAccessProxy{&_mat[index]};
}

Matrix &Mat::operator+=(const Matrix &other) noexcept {
    for (const auto &[o, n] : sv::zip(*this, other)) {
        o += n;
    }
    return *this;
}

Matrix Mat::operator+(const Matrix &other) const noexcept {
    Matrix res = *this;
    res += other;
    return res;
}

Matrix &Mat::operator-=(const Matrix &other) noexcept {
    for (const auto &[o, n] : sv::zip(*this, other)) {
        o -= n;
    }
    return *this;
}

Matrix Mat::operator-(const Matrix &other) const noexcept {
    Matrix res = *this;
    res -= other;
    return res;
}

Matrix Mat::operator*(const Matrix &other) const noexcept {
    Matrix res{};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                res[j][i] += (*this)[k][i] * other[j][k];
            }
        }
    }
    return res;
}

Matrix &Mat::operator*=(float num) noexcept {
    for (auto &f : *this) {
        f *= num;
    }
    return *this;
}

Matrix Mat::operator*(float num) const noexcept {
    Matrix res = *this;
    res *= num;
    return res;
}

Matrix &Mat::operator/=(float num) noexcept {
    for (auto &f : *this) {
        f /= num;
    }
    return *this;
}

Matrix Mat::operator/(float num) const noexcept {
    Matrix res = *this;
    res /= num;
    return res;
}

bool Mat::operator==(const Matrix &other) const noexcept {
    for (const auto &[t, o] : sv::zip(*this, other)) {
        if (t != o) {
            return false;
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, const Matrix &mat) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            os << mat[j][i];
            os << ',';
        }
        os << '\n';
    }
    return os;
}
