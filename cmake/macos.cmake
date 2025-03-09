#[=======================================================================[.rst:
MacOS
-----

This file contains functions for options and configuration for targeting the
MacOS platform

Universal Builds
----------------

To build universal binaries, ie targeting both x86_64 and arm64, use
the CMAKE_OSX_ARCHITECTURES variable prior to any project calls.
https://cmake.org/cmake/help/latest/variable/CMAKE_OSX_ARCHITECTURES.html

]=======================================================================]

# Find Requirements
if(APPLE)
    set(CMAKE_OSX_SYSROOT $ENV{SDKROOT})
    find_library(
        COCOA_LIBRARY
        REQUIRED
        NAMES Cocoa
        PATHS ${CMAKE_OSX_SYSROOT}/System/Library
        PATH_SUFFIXES Frameworks
        NO_DEFAULT_PATH
    )
endif(APPLE)

#[=============================[ MacOS Options ]=============================]
function(macos_options)
    #[[ Options from SCons
    TODO macos_deployment_target: macOS deployment target
        Default: 'default'

    TODO macos_sdk_path: macOS SDK path
        Default: ''

    TODO osxcross_sdk: OSXCross SDK version
        Default: if has_osxcross(): "darwin16" else None
    ]]
endfunction()

#[===========================[ Target Generation ]===========================]
function(macos_generate)
    target_compile_definitions(godot-cpp PUBLIC MACOS_ENABLED UNIX_ENABLED)

    target_link_options(godot-cpp PUBLIC -Wl,-undefined,dynamic_lookup)

    target_link_libraries(godot-cpp INTERFACE ${COCOA_LIBRARY})

    common_compiler_flags()
endfunction()
