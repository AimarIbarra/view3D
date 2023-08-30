#include <matrix.h>
#include <ranges>
#include <gtest/gtest.h>

const Matrix a{
    1, 2, 3, 4,
    1, 5, 9, 0,
    3, 7, 2, 1,
    4, 5, 6, 7
};

const Matrix b{
    2, 3, 5, 9,
    4, 5, 1, 7,
    1, 3, 0, 2,
    5, 2, 0, 0
};

TEST(MatrixTest, AdditionAndSubstraction) {
    EXPECT_EQ(a + b, Matrix({
          3,  5,  8, 13,
          5, 10, 10,  7,
          4, 10,  2,  3,
          9,  7,  6,  7
        }));
     
    EXPECT_EQ(a - b, Matrix({
          -1, -1, -2, -5,
          -3,  0,  8, -7,
           2,  4,  2, -1,
          -1,  3,  6,  7
        }));
}

TEST(MatrixTest, Multiplication) {
    EXPECT_EQ(a * b, Matrix({
          33, 30,  7, 29,
          31, 55, 10, 62,
          41, 52, 22, 80,
          69, 69, 25, 83
        }));
}
