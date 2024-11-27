cmake_minimum_required(VERSION 3.17)

#[=======================================================================[.rst:

CMake Version requirements
--------------------------

To enable use of the emscripten emsdk hack for pseudo shared library support
without polluting options for consumers we need to use the
CMAKE_PROJECT_<PROJECT-NAME>_INCLUDE which was introduced in version 3.17

Scons Compatibility
-------------------

As we are attempting to maintain feature parity, and ease of maintenance, these
CMake scripts are built to resemble the SCons build system.

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

#[=======================================================================[.rst:

Configurations
--------------

There are two build main configurations, 'Debug' and 'Release', these are not
related to godot's DEBUG_FEATURES flag. Build configurations change the default
compiler and linker flags present when building the library, things like debug
symbols, optimization.

The Scons build scripts don't have this concept, you can think of it like the
SCons solution has a single default configuration. In both cases overriding the
defaults is controlled by options on the command line, or in preset files.

Because of this added configuration and that it can be undefined, it becomes
important to set a default, considering the SCons solution that does not enable
debug symbols by default, it seemed appropriate to set the default to 'Release'
if unspecified. This can always be overridden like below.

.. highlight:: shell

    cmake <source> -DCMAKE_BUILD_TYPE:STRING=Debug

.. caution::

A complication arises from `Multi-Config Generators`_ that cannot have
their configuration set at configure time. This means that the configuration
must be set on the build command. This is especially important for Visual
Studio Generators which default to 'Debug'

.. highlight:: shell

    cmake --build . --config Release

.. _Multi-Config Generators:https://cmake.org/cmake/help/latest/prop_gbl/GENERATOR_IS_MULTI_CONFIG.html
]=======================================================================]
get_property( IS_MULTI_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG )
if( NOT IS_MULTI_CONFIG AND NOT CMAKE_BUILD_TYPE )
    if( GODOT_DEV_BUILD )
        set( CMAKE_BUILD_TYPE Debug )
    else ()
        set( CMAKE_BUILD_TYPE Release )
    endif ()
endif ()

#[[ Python is required for code generation ]]
find_package(Python3 3.4 REQUIRED) # pathlib should be present

# Define our project.
project( godot-cpp
        VERSION 4.4
        DESCRIPTION "C++ bindings for the Godot Engine's GDExtensions API."
        HOMEPAGE_URL "https://github.com/godotengine/godot-cpp"
        LANGUAGES CXX)

godotcpp_generate()

# Test Example
add_subdirectory( test )
