#include <matrix.h>
#include <gtest/gtest.h>

void mat2_2_eq(const Matrixf<2> &m, const Matrixf<2> &e) {
    EXPECT_EQ(m[0][0], e[0][0]);
    EXPECT_EQ(m[0][1], e[0][1]);  
    EXPECT_EQ(m[1][0], e[1][0]);  
    EXPECT_EQ(m[1][1], e[1][1]);
}

//     +------+
// a = | 1  3 |
//     | 2  4 |
//     +------+
const Matrixf<2> a{1, 2, 3, 4};

//     +------+
// b = | 2  5 |
//     | 3  9 |
//     +------+
const Matrixf<2> b{2, 3, 5, 9};

TEST(MatrixTest, AdditionAndSubstraction) {
    mat2_2_eq(a + b, {3, 5, 8, 13});
    mat2_2_eq(a - b, {-1, -1, -2, -5});
}

TEST(MatrixTest, Multiplication) {
    mat2_2_eq(a * b, {
          a[0][0] * b[0][0] + a[1][0] * b[0][1],
          a[0][1] * b[0][0] + a[1][1] * b[0][1],
          a[0][0] * b[1][0] + a[1][0] * b[1][1],
          a[0][1] * b[1][0] + a[1][1] * b[1][1]});
}

TEST(MatrixTest, DifferentDimensionMultiplication) {
    Matrixf<3, 2> m3_2{};
    Matrixf<4, 3> m4_3{};
    Matrixf<4, 2> r(m3_2 * m4_3);
    // TODO: Assign values to them and make sure the multiplication
    //       is correct.
}
