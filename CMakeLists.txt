cmake_minimum_required(VERSION 3.14)

project(TGameEngine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the engine as a subdirectory
add_subdirectory(engine)

# Add the application subdirectory
add_subdirectory(application)

# Add the common subdirectory
add_subdirectory(common)

# Optional: Enable additional warning flags for Debug builds
if(CMAKE_BUILD_TYPE MATCHES DEBUG)
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()
