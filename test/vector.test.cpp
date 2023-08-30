#include <vector.h>
#include <gtest/gtest.h>

const Vector<3> a{1, 2, 3};
const Vector<3> b{4, -2, 0};

TEST(VectorTest, AdditionAndSubstraction) {
    EXPECT_EQ(a + b, Vector<3>({5, 0, 3}));
    EXPECT_EQ(a - b, Vector<3>({-3, 4, 3}));
}

TEST(VectorTest, CrossProduct) {
    // TODO: Check for values
    (void)(a % b);
}
