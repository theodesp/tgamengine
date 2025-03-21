#include "GameCommon.h"
#include <cmath>
#include <gtest/gtest.h>

// ------------------------------------------------------------------------------------------
// Group for Attack Checking Functions
namespace AttackTests {

TEST(GameCommonTests, IsForcedAttackTest) {
  AbleToAttackType type =
      AbleToAttackType::FORCED; // Using FORCED from AbleToAttackType

  bool result = isForcedAttack(type);

  EXPECT_TRUE(result); // Expecting true since FORCED bit is set
}

TEST(GameCommonTests, IsContinuedAttackTest) {
  AbleToAttackType type =
      AbleToAttackType::CONTINUED; // Using CONTINUED from AbleToAttackType

  bool result = isContinuedAttack(type);

  EXPECT_TRUE(result); // Expecting true since CONTINUED bit is set
}

TEST(GameCommonTests, IsNotForcedAttackTest) {
  AbleToAttackType type = AbleToAttackType::CONTINUED; // Using CONTINUED

  bool result = isForcedAttack(type);

  EXPECT_FALSE(result); // Expecting false as type is CONTINUED, not FORCED
}

TEST(GameCommonTests, IsNotContinuedAttackTest) {
  AbleToAttackType type = AbleToAttackType::FORCED; // Using FORCED

  bool result = isContinuedAttack(type);

  EXPECT_FALSE(result); // Expecting false as type is FORCED, not CONTINUED
}
} // namespace AttackTests

// ------------------------------------------------------------------------------------------
// Group for Veterancy Flags Manipulation
namespace VeterancyTests {

TEST(GameCommonTests, GetVeterancyLevelFlagTest) {
  VeterancyLevelFlags flags =
      0b00000110; // Flags set for VETERAN (1 << 1) and ELITE (1 << 2)
  VeterancyLevel level =
      VeterancyLevel::VETERAN; // Using the existing enum value

  bool result = getVeterancyLevelFlag(flags, level);

  EXPECT_TRUE(result); // Expecting true since VETERAN is set in the flags
}

TEST(GameCommonTests, GetVeterancyLevelFlagInvalidLevelTest) {
  VeterancyLevelFlags flags =
      0b00000110; // Flags set for VETERAN (1 << 1) and ELITE (1 << 2)
  VeterancyLevel level = VeterancyLevel::REGULAR; // REGULAR is the lowest level

  bool result = getVeterancyLevelFlag(flags, level);

  EXPECT_TRUE(result); // Expecting true since REGULAR is set in the flags
}

TEST(GameCommonTests, SetVeterancyLevelFlagTest) {
  VeterancyLevelFlags flags = 0b00000000;       // No flags set
  VeterancyLevel level = VeterancyLevel::ELITE; // Setting ELITE level (2)

  VeterancyLevelFlags result = setVeterancyLevelFlag(flags, level);

  EXPECT_EQ(result,
            0b00000100); // Expecting flags with ELITE set (binary 00000100)
}

TEST(GameCommonTests, ClearVeterancyLevelFlagTest) {
  VeterancyLevelFlags flags =
      0b00000110; // Flags set for VETERAN (1 << 1) and ELITE (1 << 2)
  VeterancyLevel level = VeterancyLevel::VETERAN;
  VeterancyLevelFlags result = clearVeterancyLevelFlag(flags, level);
  EXPECT_EQ(result,
            0b00000100); // VETERAN flag should be cleared, leaving ELITE set
}
} // namespace VeterancyTests

// ------------------------------------------------------------------------------------------
// Group for Utility Functions
namespace UtilityTests {

TEST(GameCommonTests, ConvertDurationFromMsecsToFramesTest) {
  float msec = 1000.0f;                    // 1 second in milliseconds
  float expected = LOGICFRAMES_PER_SECOND; // Should convert to the number of
                                           // logic frames in one second

  float result = ConvertDurationFromMsecsToFrames(msec);

  EXPECT_FLOAT_EQ(result,
                  expected); // Expecting exact logic frames for 1 second
}

TEST(GameCommonTests, ConvertVelocityInSecsToFramesTest) {
  float distPerMsec = 0.02f; // 20 cm per millisecond
  float expected =
      distPerMsec *
      SECONDS_PER_LOGICFRAME_REAL; // Conversion based on the formula

  float result = ConvertVelocityInSecsToFrames(distPerMsec);

  EXPECT_FLOAT_EQ(result, expected); // Expecting the correct conversion of
                                     // distance per msec to frames
}

TEST(GameCommonTests, ConvertAccelerationInSecsToFramesTest) {
  float distPerSec2 = 9.8f; // Earth's gravity in cm/s^2
  float expected = distPerSec2 * SECONDS_PER_LOGICFRAME_REAL *
                   SECONDS_PER_LOGICFRAME_REAL; // Conversion

  float result = ConvertAccelerationInSecsToFrames(distPerSec2);

  EXPECT_FLOAT_EQ(result,
                  expected); // Expecting correct acceleration conversion
}

TEST(GameCommonTests, ConvertAngularVelocityInDegreesPerSecToRadsPerFrameTest) {
  float degPerSec = 90.0f; // 90 degrees per second

  float expected = degPerSec * (SECONDS_PER_LOGICFRAME_REAL *
                                static_cast<float>(M_PI) / 180.0f);

  float result = ConvertAngularVelocityInDegreesPerSecToRadsPerFrame(degPerSec);

  EXPECT_FLOAT_EQ(result,
                  expected); // Expecting correct angular velocity conversion
}
} // namespace UtilityTests

// ------------------------------------------------------------------------------------------
// Group for Angle Normalization
namespace AngleTests {

TEST(GameCommonTests, NormalizeAngleTest) {
  float angle = 3.5f * static_cast<float>(M_PI); // A larger angle than PI
  float expected =
      -0.5f * static_cast<float>(M_PI); // Should normalize to within [-PI, PI]

  float result = normalizeAngle(angle);

  EXPECT_FLOAT_EQ(result, expected); // Expecting normalized angle within range
}

TEST(GameCommonTests, StdAngleDiffTest) {
  float angle1 = 0.0f;
  float angle2 = 1.0f;

  float expected = 1.0f; // Difference is directly the value

  float result = stdAngleDiff(angle1, angle2);

  EXPECT_FLOAT_EQ(result, expected); // Expecting exact angle difference
}
} // namespace AngleTests
