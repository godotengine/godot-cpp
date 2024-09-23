cmake_minimum_required(VERSION 3.13)
project(godot-cpp LANGUAGES CXX)

# Get Python
find_package(Python3 3.4 REQUIRED) # pathlib should be present

if( CMAKE_C_COMPILER)
    #Silence warning from unused CMAKE_C_COMPILER from toolchain
endif ()

# Main Library
include( ${PROJECT_SOURCE_DIR}/cmake/godotcpp.cmake )

# I know this doesn't look like a typical CMakeLists.txt, but as we are
# attempting mostly feature parity with SCons, and easy maintenance, the closer
# the two build systems look the easier they will be to keep in lockstep.

# The typical target definitions are in ${PROJECT_SOURCE_DIR}/cmake/godotcpp.cmake

godotcpp_options()

godotcpp_generate()

# Test Example
add_subdirectory( test )
