#[=======================================================================[.rst:
MacOS
-----

This file contains functions for options and configuration for targeting the
MacOS platform

# To build universal binaries, ie targeting both x86_64 and arm64, use
# the CMAKE_OSX_ARCHITECTURES variable prior to any project calls.
# https://cmake.org/cmake/help/latest/variable/CMAKE_OSX_ARCHITECTURES.html

]=======================================================================]

# Find Requirements
IF(APPLE)
    set( CMAKE_OSX_SYSROOT $ENV{SDKROOT} )
    find_library( COCOA_LIBRARY REQUIRED
        NAMES Cocoa
        PATHS ${CMAKE_OSX_SYSROOT}/System/Library
        PATH_SUFFIXES Frameworks
        NO_DEFAULT_PATH)
ENDIF (APPLE)

function( macos_options )
endfunction()

function( macos_generate )

    target_compile_definitions(${TARGET_NAME}
            PUBLIC
            MACOS_ENABLED
            UNIX_ENABLED
    )

    target_link_options( ${TARGET_NAME}
            PUBLIC
            -Wl,-undefined,dynamic_lookup
    )

    target_link_libraries( ${TARGET_NAME}
            INTERFACE
            ${COCOA_LIBRARY}
    )

    common_compiler_flags()
endfunction()
