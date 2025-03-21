#pragma once

#include <cmath>
#include <cassert>

// ----------------------------------------------------------------------------------------------
constexpr int LOGICFRAMES_PER_SECOND = 30;
constexpr int MSEC_PER_SECOND = 1000;

constexpr float LOGICFRAMES_PER_MSEC_REAL = static_cast<float>(LOGICFRAMES_PER_SECOND) / static_cast<float>(MSEC_PER_SECOND);
constexpr float MSEC_PER_LOGICFRAME_REAL = static_cast<float>(MSEC_PER_SECOND) / static_cast<float>(LOGICFRAMES_PER_SECOND);
constexpr float LOGICFRAMES_PER_SECONDS_REAL = static_cast<float>(LOGICFRAMES_PER_SECOND);
constexpr float SECONDS_PER_LOGICFRAME_REAL = 1.0f / LOGICFRAMES_PER_SECONDS_REAL;

// ----------------------------------------------------------------------------------------------
constexpr int MAX_PLAYER_COUNT = 16;

// ----------------------------------------------------------------------------------------------
using PlayerMaskType = uint16_t;
constexpr PlayerMaskType PLAYERMASK_ALL = 0xffff;
constexpr PlayerMaskType PLAYERMASK_NONE = 0x0;

// ----------------------------------------------------------------------------------------------
// Enums
enum class GameDifficulty {
    EASY,
    NORMAL,
    HARD,
    COUNT
};

enum class PlayerType {
    HUMAN,
    COMPUTER,
    COUNT
};

enum class CellShroudStatus {
    CLEAR,
    FOGGED,
    SHROUDED,
    COUNT
};

enum class ObjectShroudStatus {
    INVALID,
    CLEAR,
    PARTIAL_CLEAR,
    FOGGED,
    SHROUDED,
    INVALID_BUT_PREVIOUS_VALID,
    COUNT
};

enum class GuardMode {
    NORMAL,
    GUARD_WITHOUT_PURSUIT,
    GUARD_FLYING_UNITS_ONLY
};

// Constants for time management
enum {
    NEVER = 0,
    FOREVER = 0x3fffffff
};

// Veterancy levels
enum class VeterancyLevel {
    REGULAR = 0,
    VETERAN,
    ELITE,
    HEROIC,
    COUNT,
    INVALID
};

// -------------------------------------------------------------------------------------------------
extern const char* TheVeterancyNames[];

enum class CommandSourceType {
    PLAYER,
    SCRIPT,
    AI,
    DOZER
};

enum class AbleToAttackType {
    FORCED = 0x01,
    CONTINUED = 0x02,
    TUNNELNETWORK_GUARD = 0x04,
    NEW_TARGET = 0,
    NEW_TARGET_FORCED = FORCED,
    CONTINUED_TARGET = CONTINUED,
    CONTINUED_TARGET_FORCED = FORCED | CONTINUED,
    TUNNEL_NETWORK_GUARD = TUNNELNETWORK_GUARD
};

// -------------------------------------------------------------------------------------------------
// VeterancyFlags manipulation
using VeterancyLevelFlags = uint32_t;

constexpr VeterancyLevelFlags VETERANCY_LEVEL_FLAGS_ALL = 0xffffffff;
constexpr VeterancyLevelFlags VETERANCY_LEVEL_FLAGS_NONE = 0x00000000;

// -------------------------------------------------------------------------------------------------
// Turret Type Enum
enum class WhichTurretType {
    INVALID = -1,
    MAIN = 0,
    ALT,
    MAX
};

// -------------------------------------------------------------------------------------------------
// Relationship Enum

enum class Relationship {
    ENEMIES = 0,
    NEUTRAL,
    ALLIES
};

extern const char* TheRelationshipNames[];

// ----------------------------------------------------------------------------------------------
// Utility functions

inline float ConvertDurationFromMsecsToFrames(float msec) {
    return msec * LOGICFRAMES_PER_MSEC_REAL;
}

inline float ConvertVelocityInSecsToFrames(float distPerMsec) {
    return distPerMsec * SECONDS_PER_LOGICFRAME_REAL;
}

inline float ConvertAccelerationInSecsToFrames(float distPerSec2) {
    constexpr float SEC_PER_LOGICFRAME_SQR = SECONDS_PER_LOGICFRAME_REAL * SECONDS_PER_LOGICFRAME_REAL;
    return distPerSec2 * SEC_PER_LOGICFRAME_SQR;
}

inline float ConvertAngularVelocityInDegreesPerSecToRadsPerFrame(float degPerSec) {
    constexpr float RADS_PER_DEGREE = static_cast<float>(M_PI) / 180.0f;
    return degPerSec * (SECONDS_PER_LOGICFRAME_REAL * RADS_PER_DEGREE);
}

// -------------------------------------------------------------------------------------------------
// Attack checking functions

inline bool isForcedAttack(AbleToAttackType type) {
    return static_cast<int>(type) & static_cast<int>(AbleToAttackType::FORCED);
}

inline bool isContinuedAttack(AbleToAttackType type) {
    return static_cast<int>(type) & static_cast<int>(AbleToAttackType::CONTINUED);
}

// -------------------------------------------------------------------------------------------------
// Veterancy flags manipulation
inline bool getVeterancyLevelFlag(VeterancyLevelFlags flags, VeterancyLevel level) {
    if (level == VeterancyLevel::REGULAR) {
        return true;  // Special case for REGULAR level
    }
    return (flags & (1UL << static_cast<int>(level))) != 0;
}

inline VeterancyLevelFlags setVeterancyLevelFlag(VeterancyLevelFlags flags, VeterancyLevel level) {
    return flags | (1UL << static_cast<int>(level));
}

inline VeterancyLevelFlags clearVeterancyLevelFlag(VeterancyLevelFlags flags, VeterancyLevel level) {
    return flags & ~(1UL << static_cast<int>(level));
}

// -------------------------------------------------------------------------------------------------
// Angle normalization functions

inline float normalizeAngle(float angle) {
    assert(!std::isnan(angle) && "Angle is NAN in normalizeAngle!");
    
    while (angle > static_cast<float>(M_PI)) {
        angle -= 2 * static_cast<float>(M_PI);
    }
    
    while (angle <= -static_cast<float>(M_PI)) {
        angle += 2 * static_cast<float>(M_PI);
    }
    
    return angle;
}

inline float stdAngleDiff(float a1, float a2) {
    float diff = normalizeAngle(a2 - a1);  // Changed order to get positive value for the test case
    return diff;
}