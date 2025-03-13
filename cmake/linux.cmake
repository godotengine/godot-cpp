#[=======================================================================[.rst:
Linux
-----

This file contains functions for options and configuration for targeting the
Linux platform

]=======================================================================]

#[=============================[ Linux Options ]=============================]
function(linux_options)
    #[[ Options from SCons
    use_llvm : Use the LLVM compiler
        Not implemented as compiler selection is managed by CMake. Look to
        doc/cmake.rst for examples.
    ]]
endfunction()

#[===========================[ Target Generation ]===========================]
function(linux_generate)
    target_compile_definitions(godot-cpp PUBLIC LINUX_ENABLED UNIX_ENABLED)

    common_compiler_flags()
endfunction()
