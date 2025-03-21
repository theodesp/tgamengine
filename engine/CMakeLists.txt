cmake_minimum_required(VERSION 3.14)
project(Engine)

# Find SDL2 package
find_package(SDL2 REQUIRED)
find_package(EnTT CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

# Add the include directories for the engine and SDL2
include_directories(include)
include_directories(${SDL2_INCLUDE_DIRS})  # Add SDL2 headers to the include paths

# Specify the source files for the engine
set(SOURCE_FILES
    src/Engine.cpp
    src/Graphics.cpp
)

# Create the engine static library
add_library(Engine STATIC ${SOURCE_FILES})

# Link SDL2
target_link_libraries(Engine PRIVATE SDL2::SDL2)
target_include_directories(Engine PRIVATE ${SDL2_INCLUDE_DIRS})

target_link_libraries(Engine PRIVATE EnTT::EnTT)
target_link_libraries(Engine PRIVATE glm::glm)

# Add the tests subdirectory
enable_testing()
add_subdirectory(tests)