cmake_minimum_required(VERSION 3.14)
project(CommonTests)

find_package(GTest CONFIG REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/common/include)

# Add test executable
add_executable(common_tests 
    test_stringutils.cpp
    test_wstringutils.cpp
    test_errors.cpp
    test_gamecommon.cpp
)

# Link GoogleTest
target_link_libraries(common_tests PRIVATE GTest::gtest GTest::gtest_main)

target_sources(common_tests PRIVATE 
    ${CMAKE_SOURCE_DIR}/common/src/Errors.cpp
)

# Add test discovery
include(GoogleTest)
enable_testing()
gtest_discover_tests(common_tests)