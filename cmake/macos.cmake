#[=======================================================================[.rst:
MacOS
-----

This file contains functions for options and configuration for targeting the
MacOS platform

]=======================================================================]

#[===========================[ Find Dependencies ]===========================]
# APPLE is set to True when the target system is an Apple platform
# (macOS, iOS, tvOS, visionOS or watchOS).
if( APPLE )
    set( CMAKE_OSX_SYSROOT $ENV{SDKROOT} )
    find_library( COCOA_LIBRARY REQUIRED
        NAMES Cocoa
        PATHS ${CMAKE_OSX_SYSROOT}/System/Library
        PATH_SUFFIXES Frameworks
        NO_DEFAULT_PATH )
endif( APPLE )

#[=============================[ MacOS Options ]=============================]
function( macos_options )
    # TODO "macos_deployment_target" "macOS deployment target" "default"
    # TODO "macos_sdk_path" "macOS SDK path" ""
    # TODO if has_osxcross(): "osxcross_sdk" "OSXCross SDK version" "darwin16"
endfunction()

#[===========================[ Target Generation ]===========================]
function( macos_generate )

    # OSX_ARCHITECTURES does not support generator expressions.
    if( NOT GODOT_ARCH OR GODOT_ARCH STREQUAL universal )
        set( OSX_ARCH "x86_64;arm64" )
        set( SYSTEM_ARCH universal )
    else()
        set( OSX_ARCH ${GODOT_ARCH} )
    endif()

    set_target_properties( ${TARGET_NAME}
            PROPERTIES

            # Specify multiple architectures for universal builds
            OSX_ARCHITECTURES "${OSX_ARCH}"
            GODOT_ARCH ${SYSTEM_ARCH}
    )

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
