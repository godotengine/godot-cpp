#[=======================================================================[.rst:
Windows
-------

This file contains functions for options and configuration for targeting the
Windows platform

]=======================================================================]

function( windows_options )

    option( GODOT_USE_STATIC_CPP "Link MinGW/MSVC C++ runtime libraries statically" ON )

    option( GODOT_DEBUG_CRT "Compile with MSVC's debug CRT (/MDd)" OFF )

endfunction()

function( windows_generate TARGET_NAME )
    set( IS_MSVC "$<CXX_COMPILER_ID:MSVC>" )
    set( IS_CLANG "$<OR:$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:Clang>>" )
    set( NOT_MSVC "$<NOT:${IS_MSVC}>" )
    set( STATIC_CPP "$<BOOL:${GODOT_USE_STATIC_CPP}>")
    set( DISABLE_EXCEPTIONS "$<BOOL:${GODOT_DISABLE_EXCEPTIONS}>")
    set( DEBUG_CRT "$<BOOL:${GODOT_DEBUG_CRT}>" )
    set( MSVC_RUNTIME "$<IF:${DEBUG_CRT},MultiThreadedDebugDLL,$<IF:${STATIC_CPP},MultiThreaded,MultiThreadedDLL>>" )

    set_target_properties( ${TARGET_NAME}
            PROPERTIES
            PDB_OUTPUT_DIRECTORY "$<1:${CMAKE_SOURCE_DIR}/bin>"

            # set msvc runtime to link against and for our consumers
            MSVC_RUNTIME_LIBRARY "${MSVC_RUNTIME}"
            INTERFACE_MSVC_RUNTIME_LIBRARY "${MSVC_RUNTIME}"
    )

    target_compile_definitions( ${TARGET_NAME}
        PUBLIC
            WINDOWS_ENABLED
            $<${IS_MSVC}:
                TYPED_METHOD_BIND
                NOMINMAX
            >
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
