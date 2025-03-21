#include "Errors.h"
#include <gtest/gtest.h>

// Test error message retrieval
TEST(ErrorCodeTest, TestGetErrorMessage) {
    EXPECT_EQ(getErrorMessage(ErrorCode::Bug), "Unexpected bug encountered.");
    EXPECT_EQ(getErrorMessage(ErrorCode::OutOfMemory), "Out of memory: Unable to allocate resources.");
    EXPECT_EQ(getErrorMessage(ErrorCode::BadArgument), "Invalid argument provided.");
    EXPECT_EQ(getErrorMessage(ErrorCode::InvalidFileVersion), "Unrecognized file version format.");
    EXPECT_EQ(getErrorMessage(ErrorCode::CorruptFileFormat), "File format is corrupt or unreadable.");
    EXPECT_EQ(getErrorMessage(ErrorCode::BadIniData), "Configuration file contains invalid data.");
}

// Test unknown error handling
TEST(ErrorCodeTest, TestUnknownError) {
    EXPECT_EQ(getErrorMessage(static_cast<ErrorCode>(0xBAD9999)), "Unknown error");
}