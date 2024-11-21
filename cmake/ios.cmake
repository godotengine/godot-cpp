#[=======================================================================[.rst:
Ios
---

This file contains functions for options and configuration for targeting the
Ios platform

]=======================================================================]
function(ios_options)
    # iOS options
endfunction()

function(ios_generate TARGET_NAME)

    target_compile_definitions(${TARGET_NAME}
            PUBLIC
            IOS_ENABLED
            UNIX_ENABLED
    )

    common_compiler_flags(${TARGET_NAME})
endfunction()
