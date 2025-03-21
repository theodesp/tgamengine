#include <gtest/gtest.h>
#include "Math/BaseTypes.h"

TEST(MathTest, SquareFunction) {
    EXPECT_EQ(Math::sqr(2), 4);
    EXPECT_EQ(Math::sqr(-3), 9);
    EXPECT_FLOAT_EQ(Math::sqr(1.5f), 2.25f);
}

TEST(MathTest, Clamping) {
    EXPECT_EQ(Math::clamp(5, 0, 10), 5);
    EXPECT_EQ(Math::clamp(-1, 0, 10), 0);
    EXPECT_EQ(Math::clamp(15, 0, 10), 10);
}

TEST(MathTest, SignFunction) {
    EXPECT_EQ(Math::sign(-10), -1);
    EXPECT_EQ(Math::sign(10), 1);
    EXPECT_EQ(Math::sign(0), 0);
}