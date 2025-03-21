#include "Errors.h"
#include <unordered_map>
using namespace std;

// Function implementation
std::string getErrorMessage(ErrorCode error) {
    static const std::unordered_map<ErrorCode, std::string> errorMessages = {
        { ErrorCode::Bug, "Unexpected bug encountered." },
        { ErrorCode::OutOfMemory, "Out of memory: Unable to allocate resources." },
        { ErrorCode::BadArgument, "Invalid argument provided." },
        { ErrorCode::InvalidFileVersion, "Unrecognized file version format." },
        { ErrorCode::CorruptFileFormat, "File format is corrupt or unreadable." },
        { ErrorCode::BadIniData, "Configuration file contains invalid data." },
    };

    auto it = errorMessages.find(error);
    return (it != errorMessages.end()) ? it->second : "Unknown error";
}