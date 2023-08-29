#pragma once

class Matrix4f
{
public:
    Matrix4f() noexcept;
    Matrix4f(float *value) noexcept;
    Matrix4f(const Matrix4f &mat) noexcept;

    float get(int x, int y) noexcept;
    void set(int x, int y, float value) noexcept;

    static Matrix4f Identity() noexcept;
    static Matrix4f Null() noexcept;

    static Matrix4f add(Matrix4f &mat1, Matrix4f &mat2) noexcept;
    static Matrix4f sub(Matrix4f &mat1, Matrix4f &mat2) noexcept;
    static Matrix4f mul(Matrix4f &mat1, Matrix4f &mat2) noexcept;
    static Matrix4f scaler_mul(Matrix4f &mat1, float num) noexcept;
    static Matrix4f scaler_div(Matrix4f &mat1, float num);

    Matrix4f operator+(Matrix4f &mat) noexcept;
    Matrix4f operator-(Matrix4f &mat) noexcept;
    Matrix4f operator*(Matrix4f &mat) noexcept;
    Matrix4f operator*(float num) noexcept;
    Matrix4f operator/(float num);

private:
    float matf[16]{};
};