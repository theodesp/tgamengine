#include "Debug.h"

int main() {
    Debug::Init("log.txt");

    DEBUG_LOG("Application started.");
    DEBUG_WARN("Low memory warning.");
    DEBUG_ERROR("File not found.");

    // Simulate a crash
    DEBUG_CRASH("Null pointer detected!");

    Debug::Shutdown();
    return 0;
}