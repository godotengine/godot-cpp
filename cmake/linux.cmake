#[=======================================================================[.rst:
Linux
-----

This file contains functions for options and configuration for targeting the
Linux platform

]=======================================================================]

#[=============================[ Linux Options ]=============================]
function( linux_options )
    #[[ The options present in the SCons build shown below are managed by
    toolchain files, further information can be found in doc/cmake.rst

    use_llvm : Use the LLVM compiler
        Default: False
]]
endfunction()

#[===========================[ Target Generation ]===========================]
function( linux_generate )
    target_compile_definitions( ${TARGET_NAME}
            PUBLIC
            LINUX_ENABLED
            UNIX_ENABLED
    )

    common_compiler_flags()
endfunction()
