cmake_minimum_required(VERSION 3.13)
project(godot-cpp LANGUAGES CXX)

# Configure CMake
# https://discourse.cmake.org/t/how-do-i-remove-compile-options-from-target/5965
# https://stackoverflow.com/questions/74426638/how-to-remove-rtc1-from-specific-target-or-file-in-cmake
if(${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    if(NOT CMAKE_BUILD_TYPE MATCHES Debug)
        STRING(REGEX REPLACE "/RTC(su|[1su])" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
        string(REPLACE "/RTC1" "" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
    endif ()
endif ()

include( ${PROJECT_SOURCE_DIR}/cmake/godotcpp.cmake )

# I know this doesn't look like a typical CMakeLists.txt, but as we are
# attempting mostly feature parity with SCons, and easy maintenance, the closer
# the two build systems look the easier they will be to keep in lockstep.

# The typical target definitions are in ${PROJECT_SOURCE_DIR}/cmake/godotcpp.cmake

godotcpp_options()

godotcpp_generate()
