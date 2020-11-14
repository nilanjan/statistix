cmake_minimum_required(VERSION 3.12)
project(Statistix)

Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(SOURCE_FILES src/statistix.hpp tests/main.cpp tests/TestCase.cpp tests/TestCase.hpp)

add_executable(testStatistix ${SOURCE_FILES})
target_link_libraries(testStatistix Catch2::Catch2)

target_include_directories(testStatistix PUBLIC ${PROJECT_SOURCE_DIR}/include)
