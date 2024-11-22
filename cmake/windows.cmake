#[=======================================================================[.rst:
Windows
-------

This file contains functions for options and configuration for targeting the
Windows platform

]=======================================================================]

function( windows_options )

    option( GODOT_USE_STATIC_CPP "Link MinGW/MSVC C++ runtime libraries statically" ON )

    # The below scons variables are controlled via toolchain files instead
    # "mingw_prefix"    "MinGW prefix"
    # "use_llvm"        "Use the LLVM compiler (MVSC or MinGW depending on the use_mingw flag)"
    # "use_mingw"       "Use the MinGW compiler instead of MSVC - only effective on Windows"
endfunction()

function( windows_generate TARGET_NAME )
    set( IS_MSVC "$<CXX_COMPILER_ID:MSVC>" )
    set( IS_CLANG "$<OR:$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:Clang>>" )
    set( NOT_MSVC "$<NOT:${IS_MSVC}>" )
    set( STATIC_CPP "$<BOOL:${GODOT_USE_STATIC_CPP}>")
    set( DISABLE_EXCEPTIONS "$<BOOL:${GODOT_DISABLE_EXCEPTIONS}>")

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
            $<${IS_MSVC}:
                $<IF:${STATIC_CPP},/MT,/MD>$<${IS_DEV}:d> # Link microsoft runtime
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
