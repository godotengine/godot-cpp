#[=======================================================================[.rst:
Windows
-------

This file contains functions for options and configuration for targeting the
Windows platform

MSVC Runtime Selection
----------------------

There are two main ways to set the msvc runtime library;
Using ``target_compile_options()`` to add the flags
or using the ``CMAKE_MSVC_RUNTIME_LIBRARY`` property_ abstraction, introduced
in CMake version 3.15 with the policy CMP0091_ to remove the flags from
``CMAKE_<LANG>_FLAGS_<CONFIG>``.

Default: ``CMAKE_MSVC_RUNTIME_LIBRARY="MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"``

This initializes each target's ``MSVC_RUNTIME_LIBRARY`` property at the time of
target creation.

This creates a conundrum for us, the ``CMAKE_MSVC_RUNTIME_LIBRARY`` needs to be
correct at the time the target is created, but we have no control over the
consumers CMake scripts, and the per-target ``MSVC_RUNTIME_LIBRARY`` property
is not transient.

We need ``CMAKE_MSVC_RUNTIME_LIBRARY`` to be ``"$<1:>"`` to ensure it
will not add any flags. And then use ``target_compile_options()`` so that our
flags will propagate to consumers.

In the interests of playing nicely we detect whether we are being consumed
and notify the consumer that we are setting ``CMAKE_MSVC_RUNTIME_LIBRARY``,
that dependent targets rely on it, and point them to these comments as to why.

.. _CMP0091:https://cmake.org/cmake/help/latest/policy/CMP0091.html
.. _property:https://cmake.org/cmake/help/latest/variable/CMAKE_MSVC_RUNTIME_LIBRARY.html
.. https://discourse.cmake.org/t/mt-staticrelease-doesnt-match-value-md-dynamicrelease/5428/4

]=======================================================================]
if( PROJECT_NAME ) # we are not the top level if this is true
    if( DEFINED CMAKE_MSVC_RUNTIME_LIBRARY )
        # Warning that we are clobbering the variable.
        message( WARNING "setting CMAKE_MSVC_RUNTIME_LIBRARY to \"$<1:>\"")
    else(  )
        # Notification that we are setting the variable
        message( STATUS "setting CMAKE_MSVC_RUNTIME_LIBRARY to \"$<1:>\"")
    endif()
endif()
set( CMAKE_MSVC_RUNTIME_LIBRARY "$<1:>" CACHE INTERNAL "Select the MSVC runtime library for use by compilers targeting the MSVC ABI." )

#[============================[ Windows Options ]============================]
function( windows_options )

    option( GODOT_USE_STATIC_CPP "Link MinGW/MSVC C++ runtime libraries statically" ON )

    option( GODOT_DEBUG_CRT "Compile with MSVC's debug CRT (/MDd)" OFF )

endfunction()

#[===========================[ Target Generation ]===========================]
function( windows_generate TARGET_NAME )
    set( STATIC_CPP "$<BOOL:${GODOT_USE_STATIC_CPP}>")
    set( DEBUG_CRT "$<BOOL:${GODOT_DEBUG_CRT}>" )

    set_target_properties( ${TARGET_NAME}
            PROPERTIES
            PDB_OUTPUT_DIRECTORY "$<1:${CMAKE_SOURCE_DIR}/bin>"
    )

    target_compile_definitions( ${TARGET_NAME}
        PUBLIC
            WINDOWS_ENABLED
            $<${IS_MSVC}:
                TYPED_METHOD_BIND
                NOMINMAX
            >
    )

    target_compile_options( ${TARGET_NAME}
        PUBLIC
            $<${IS_MSVC}:$<IF:${DEBUG_CRT},/MDd,$<IF:${STATIC_CPP},/MT,/MD>>>
    )

    target_link_options( ${TARGET_NAME}
            PUBLIC

            $<${NOT_MSVC}:
                -Wl,--no-undefined
                $<${STATIC_CPP}:
                    -static
                    -static-libgcc
                    -static-libstdc++
                >
            >

            $<${IS_CLANG}:-lstdc++>
    )

    common_compiler_flags( ${TARGET_NAME} )
endfunction()
