#include <vector.h>
#include <gtest/gtest.h>

const Vectorf<3> a{1, 2, 3};
const Vectorf<3> b{4, -2, 0};

// TODO: Lazy me didn't implement this as a function.
#define EXPECT_V3_EQ(v, x, y, z)                \
    EXPECT_EQ(v[0], x);                         \
    EXPECT_EQ(v[1], y);                         \
    EXPECT_EQ(v[2], z)

TEST(VectorTest, AdditionAndSubstraction) {
    Vectorf<3> r = a + b;
    EXPECT_V3_EQ(r, 5, 0, 3);

    r = a - b;
    EXPECT_V3_EQ(r, -3, 4, 3);
}

TEST(VectorTest, CrossProduct) {
    // TODO: Check for values
    Vectorf<3> r = a % b;
    (void)r;
}
