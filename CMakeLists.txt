cmake_minimum_required(VERSION 3.12)
project(Statistix)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(SOURCE_FILES src/statistix.hpp tests/main.cpp tests/TestCase.cpp tests/TestCase.hpp)

find_package(Catch2 REQUIRED)

add_executable(testStatistix ${SOURCE_FILES})
target_link_libraries(testStatistix Catch2::Catch2 Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(testStatistix)