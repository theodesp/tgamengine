cmake_minimum_required(VERSION 3.14)
project(EngineTests)

find_package(GTest CONFIG REQUIRED)

# Add test executable
add_executable(engine_tests 
    test_math.cpp
    test_trig.cpp
)

# Link GoogleTest
target_link_libraries(engine_tests PRIVATE GTest::gtest GTest::gtest_main)

# Add test discovery
include(GoogleTest)
enable_testing()
gtest_discover_tests(engine_tests)