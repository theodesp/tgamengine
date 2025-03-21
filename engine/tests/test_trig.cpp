#include <gtest/gtest.h>
#include "Math/Trig.h"

TEST(TrigTests, SinTest) {
    EXPECT_NEAR(Trig::Sin(0.0f), 0.0f, 1e-6);
    EXPECT_NEAR(Trig::Sin(M_PI / 2), 1.0f, 1e-6);
}

TEST(TrigTests, CosTest) {
    EXPECT_NEAR(Trig::Cos(0.0f), 1.0f, 1e-6);
    EXPECT_NEAR(Trig::Cos(M_PI), -1.0f, 1e-6);
}

TEST(TrigTests, TanTest) {
    EXPECT_NEAR(Trig::Tan(0.0f), 0.0f, 1e-6);
}

TEST(TrigTests, ACosTest) {
    EXPECT_NEAR(Trig::ACos(1.0f), 0.0f, 1e-6);
}

TEST(TrigTests, ASinTest) {
    EXPECT_NEAR(Trig::ASin(0.0f), 0.0f, 1e-6);
}