cmake_minimum_required(VERSION 3.14)
project(Application)

# Find SDL2 package
find_package(SDL2 REQUIRED)

# Add the include directories for the engine and SDL2
include_directories(${CMAKE_SOURCE_DIR}/engine/include)
include_directories(${SDL2_INCLUDE_DIRS}) 

# Specify the source files for the application
set(SOURCE_FILES
    src/Application.cpp
)

# Create the application executable
add_executable(TGameEngineApp ${SOURCE_FILES})

# Link the libraries to the application
target_link_libraries(TGameEngineApp PRIVATE 
    SDL2::SDL2 
    SDL2::SDL2main 
    Engine
    Common
)

# Optional: Include additional directories if needed
target_include_directories(TGameEngineApp PRIVATE 
    ${SDL2_INCLUDE_DIRS} 
    ${CMAKE_SOURCE_DIR}/engine/include
    ${CMAKE_SOURCE_DIR}/common/include
)