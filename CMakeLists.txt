cmake_minimum_required(VERSION 3.22)
project(SBExercise3041)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(BUILD_CPR_TEST OFF)
set(CMAKE_USE_OPENSSL OFF)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 871ed52d350214a034f6ef8a3b8f51c5ce1bd400) # The commit hash for 1.9.0.
FetchContent_MakeAvailable(cpr)

add_executable(SBExercise3041 main.cpp)

target_link_libraries(SBExercise3041 PRIVATE cpr::cpr)

