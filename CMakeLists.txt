cmake_minimum_required(VERSION 3.17)

#[=======================================================================[.rst:

CMake Version requirements
--------------------------

To enable use of the emscripten emsdk hack for pseudo shared library support
without polluting options for consumers we need to use the
CMAKE_PROJECT_<PROJECT-NAME>_INCLUDE which was introduced in version 3.17

Scons Compatibility
-------------------

There is an understandable conflict between build systems as they define
similar concepts in different ways. When there isn't a 1:1 relationship,
compromises need to be made to resolve those differences.

As we are attempting to maintain feature parity, and ease of maintenance, these
CMake scripts are built to resemble the SCons build system wherever possible.

The file structure and file content are made to match, if not in content then
in spirit. The closer the two build systems look the easier they will be to
maintain.

Where the SCons additional scripts in the tools directory, The CMake scripts
are in the cmake directory.

For example, the tools/godotcpp.py is sourced into SCons, and the 'options'
function is run.

.. highlight:: python

    cpp_tool = Tool("godotcpp", toolpath=["tools"])
    cpp_tool.options(opts, env)

The CMake equivalent is below.
]=======================================================================]

include( cmake/godotcpp.cmake )

godotcpp_options()

# Define our project.
project( godot-cpp
        VERSION 4.4
        DESCRIPTION "C++ bindings for the Godot Engine's GDExtensions API."
        HOMEPAGE_URL "https://github.com/godotengine/godot-cpp"
        LANGUAGES CXX)

compiler_detection()
godotcpp_generate()

# Conditionally enable the godot-cpp.test.<target> integration testing targets
if( GODOTCPP_ENABLE_TESTING )
    add_subdirectory( test )
endif()

# If this is the top level CMakeLists.txt, Generators which honor the
# USE_FOLDERS flag will organize godot-cpp targets under the subfolder
# 'godot-cpp'. This is enable by default from CMake version 3.26
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
