#pragma once

#include <fstream>
#include <mutex>
#include <string>

class Debug {
public:
    enum class Level {
        Info,
        Warning,
        Error,
        Fatal
    };

    // Initialize logging
    static void Init(const std::string& logFile = "debug.log");

    // Shut down logging
    static void Shutdown();

    // Log a message with a severity level
    static void Log(Level level, const std::string& message);

    // Handle crashes
    static void Crash(const std::string& reason);

private:
    Debug() = default;
    static Debug& instance();

    std::ofstream logStream;
    std::mutex logMutex;
};

// Macros for convenient logging
#define DEBUG_LOG(msg) Debug::Log(Debug::Level::Info, msg)
#define DEBUG_WARN(msg) Debug::Log(Debug::Level::Warning, msg)
#define DEBUG_ERROR(msg) Debug::Log(Debug::Level::Error, msg)
#define DEBUG_CRASH(msg) Debug::Crash(msg)
