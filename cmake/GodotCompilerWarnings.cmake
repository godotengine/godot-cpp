# Add warnings based on compiler & version
# Set some helper variables for readability
set( compiler_less_than_v8 "$<VERSION_LESS:$<CXX_COMPILER_VERSION>,8>" )
set( compiler_greater_than_or_equal_v9 "$<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,9>" )
set( compiler_greater_than_or_equal_v11 "$<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,11>" )
set( compiler_less_than_v11 "$<VERSION_LESS:$<CXX_COMPILER_VERSION>,11>" )
set( compiler_greater_than_or_equal_v12 "$<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,12>" )

# These compiler options reflect what is in godot/SConstruct.
target_compile_options( ${PROJECT_NAME} PRIVATE
    # MSVC only
    $<${compiler_is_msvc}:
        /W4

        # Disable warnings which we don't plan to fix.
        /wd4100  # C4100 (unreferenced formal parameter): Doesn't play nice with polymorphism.
        /wd4127  # C4127 (conditional expression is constant)
        /wd4201  # C4201 (non-standard nameless struct/union): Only relevant for C89.
        /wd4244  # C4244 C4245 C4267 (narrowing conversions): Unavoidable at this scale.
        /wd4245
        /wd4267
        /wd4305  # C4305 (truncation): double to float or real_t, too hard to avoid.
        /wd4514  # C4514 (unreferenced inline function has been removed)
        /wd4714  # C4714 (function marked as __forceinline not inlined)
        /wd4820  # C4820 (padding added after construct)
    >

    # Clang and GNU common options
    $<$<OR:${compiler_is_clang},${compiler_is_gnu}>:
        -Wall
        -Wctor-dtor-privacy
        -Wextra
        -Wno-unused-parameter
        -Wnon-virtual-dtor
        -Wwrite-strings
    >

    # Clang only
    $<${compiler_is_clang}:
        -Wimplicit-fallthrough
        -Wno-ordered-compare-function-pointers
    >

    # GNU only
    $<${compiler_is_gnu}:
        -Walloc-zero
        -Wduplicated-branches
        -Wduplicated-cond
        -Wno-misleading-indentation
        -Wplacement-new=1
        -Wshadow-local
        -Wstringop-overflow=4
    >
    $<$<AND:${compiler_is_gnu},${compiler_less_than_v8}>:
        # Bogus warning fixed in 8+.
        -Wno-strict-overflow
    >
    $<$<AND:${compiler_is_gnu},${compiler_greater_than_or_equal_v9}>:
        -Wattribute-alias=2
    >
    $<$<AND:${compiler_is_gnu},${compiler_greater_than_or_equal_v11}>:
        # Broke on MethodBind templates before GCC 11.
        -Wlogical-op
    >
    $<$<AND:${compiler_is_gnu},${compiler_less_than_v11}>:
        # Regression in GCC 9/10, spams so much in our variadic templates that we need to outright disable it.
        -Wno-type-limits
    >
    $<$<AND:${compiler_is_gnu},${compiler_greater_than_or_equal_v12}>:
        # False positives in our error macros, see GH-58747.
        -Wno-return-type
    >
)

# Treat warnings as errors
function( set_warning_as_error )
    message( STATUS "[${PROJECT_NAME}] Treating warnings as errors")
    if ( CMAKE_VERSION VERSION_GREATER_EQUAL "3.24" )
        set_target_properties( ${PROJECT_NAME}
            PROPERTIES
                COMPILE_WARNING_AS_ERROR ON
        )
    else()
        target_compile_options( ${PROJECT_NAME}
            PRIVATE
                $<${compiler_is_msvc}:/WX>
                $<$<OR:${compiler_is_clang},${compiler_is_gnu}>:-Werror>
        )
    endif()
endfunction()

if ( GODOT_CPP_WARNING_AS_ERROR )
    set_warning_as_error()
endif()
