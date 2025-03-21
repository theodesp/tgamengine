cmake_minimum_required(VERSION 3.14)
project(Common)

include_directories(include)
# Specify the source files for the engine
set(SOURCE_FILES
    src/Errors.cpp
    src/Debug.cpp
)

# Create the engine static library
add_library(Common STATIC ${SOURCE_FILES})

# Add the tests subdirectory
enable_testing()
add_subdirectory(tests)