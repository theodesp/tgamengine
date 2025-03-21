#include "Debug.h"
#include <iostream>

Debug& Debug::instance() {
    static Debug debugInstance;
    return debugInstance;
}

void Debug::Init(const std::string& logFile) {
    instance().logStream.open(logFile, std::ios::out | std::ios::app);

    if (!instance().logStream.is_open()) {
        std::cerr << "[ERROR] Failed to open or create the log file: " << logFile << std::endl;
        std::abort();  // Optional: or handle the error in another way
    }
}

void Debug::Shutdown() {
    if (instance().logStream.is_open()) {
        instance().logStream.close();
    }
}

void Debug::Log(Level level, const std::string& message) {
    std::lock_guard<std::mutex> lock(instance().logMutex);

    std::string levelStr;
    switch (level) {
        case Level::Info:    levelStr = "[INFO] "; break;
        case Level::Warning: levelStr = "[WARNING] "; break;
        case Level::Error:   levelStr = "[ERROR] "; break;
        case Level::Fatal:   levelStr = "[FATAL] "; break;
    }

    std::string logMessage = levelStr + message;
    std::cout << logMessage << std::endl;

    if (instance().logStream.is_open()) {
        instance().logStream << logMessage << std::endl;
    }
}

void Debug::Crash(const std::string& reason) {
    Log(Level::Fatal, "Application crashed: " + reason);
    std::abort();
}
