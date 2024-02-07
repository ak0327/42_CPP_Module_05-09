cmake_minimum_required(VERSION 3.21)
project(ex01)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address,undefined -fno-omit-frame-pointer")


# google test ------------------------------------------------------------------
include(FetchContent)
include(GoogleTest)

FetchContent_Declare(
        googletest
        DOWNLOAD_EXTRACT_TIMESTAMP true
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
# ------------------------------------------------------------------------------

include_directories(.)
add_executable(RPN main.cpp RPN.cpp)
add_executable(unit_test TestOverflow.cpp TestRPN.cpp RPN.cpp)

target_link_libraries(
        unit_test
        GTest::gtest_main
)

gtest_discover_tests(unit_test)
