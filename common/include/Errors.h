#pragma once

#include <string>

enum class ErrorCode : uint32_t {
    Bug = 0xBAD0001,               // Should not be possible under normal operation
    OutOfMemory,                    // Unable to allocate memory
    BadArgument,                    // Generic "bad argument"
    InvalidFileVersion,              // Unrecognized file version
    CorruptFileFormat,               // Invalid file format
    BadIniData,                      // Bad INI data
};

std::string getErrorMessage(ErrorCode error);