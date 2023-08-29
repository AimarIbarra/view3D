#include "matrix4f.h"

Matrix4f::Matrix4f() noexcept { }

Matrix4f::Matrix4f(float *value) noexcept
{
    for (int i = 0; i < 16; i++)
    {
        this->matf[i] = value[i];
    }
}

Matrix4f::Matrix4f(const Matrix4f &mat) noexcept
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            this->matf[i * 4 + j] = mat.matf[i * 4 + j];
        }
    }
}

float Matrix4f::get(int x, int y) noexcept
{
    return this->matf[x * 4 + y];
}

void Matrix4f::set(int x, int y, float value) noexcept
{
    this->matf[x * 4 + y] = value;
}

Matrix4f Matrix4f::Identity() noexcept
{
    Matrix4f mat = Matrix4f();

    for (int i = 0; i < 4; i++)
    {
        mat.set(i, i, 1);
    }

    return mat;
}

Matrix4f Matrix4f::Null() noexcept
{
    return Matrix4f();
}

Matrix4f Matrix4f::add(Matrix4f &mat1, Matrix4f &mat2) noexcept
{
    Matrix4f mat = Matrix4f();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mat.set(i, j, mat1.get(i, j) + mat2.get(i, j));
        }
    }
    return mat;
}

Matrix4f Matrix4f::sub(Matrix4f &mat1, Matrix4f &mat2) noexcept
{
    Matrix4f mat = Matrix4f();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mat.set(i, j, mat1.get(i, j) - mat2.get(i, j));
        }
    }
    return mat;
}

Matrix4f Matrix4f::mul(Matrix4f &mat1, Matrix4f &mat2) noexcept
{
    Matrix4f mat = Matrix4f();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                mat.set(i, j, mat.get(i, j) + mat1.get(i, k) * mat2.get(k, j));
            }
        }
    }
    return mat;
}

Matrix4f Matrix4f::scaler_mul(Matrix4f &mat1, float num) noexcept
{
    Matrix4f mat = Matrix4f();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mat.set(i, j, mat1.get(i, j) * num);
        }
    }
    return mat;
}

Matrix4f Matrix4f::scaler_div(Matrix4f &mat1, float num)
{
    Matrix4f mat = Matrix4f();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mat.set(i, j, mat1.get(i, j) / num);
        }
    }
    return mat;
}

Matrix4f Matrix4f::operator+(Matrix4f &mat) noexcept
{
    return Matrix4f::add(*this, mat);
}

Matrix4f Matrix4f::operator-(Matrix4f &mat) noexcept
{
    return Matrix4f::sub(*this, mat);
}

Matrix4f Matrix4f::operator*(Matrix4f &mat) noexcept
{
    return Matrix4f::mul(*this, mat);
}

Matrix4f Matrix4f::operator*(float num) noexcept
{
    return Matrix4f::scaler_mul(*this, num);
}

Matrix4f Matrix4f::operator/(float num)
{
    return Matrix4f::scaler_div(*this, num);
}
