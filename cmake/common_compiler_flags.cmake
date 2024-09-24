#Generator Expression Helpers
set( IS_CLANG "$<OR:$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:Clang>>" )
set( IS_GNU "$<CXX_COMPILER_ID:GNU>" )
set( IS_MSVC "$<CXX_COMPILER_ID:MSVC>" )

set( GNU_LT_V8 "$<VERSION_LESS:$<CXX_COMPILER_VERSION>,8>" )
set( GNU_GE_V9 "$<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,9>" )
set( GNU_GT_V11 "$<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,11>" )
set( GNU_LT_V11 "$<VERSION_LESS:$<CXX_COMPILER_VERSION>,11>" )
set( GNU_GE_V12 "$<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,12>" )

set( WARNING_AS_ERROR "$<BOOL:${GODOT_WARNING_AS_ERROR}>")

set( NOT_RELEASE "$<NOT:$<CONFIG:Release>>")

set( HOT_RELOAD-UNSET "$<STREQUAL:${GODOT_USE_HOT_RELOAD},>")
set( HOT_RELOAD "$<IF:${HOT_RELOAD-UNSET},${NOT_RELEASE},$<BOOL:${GODOT_USE_HOT_RELOAD}>>" )

set( DISABLE_EXCEPTIONS "$<BOOL:${GODOT_DISABLE_EXCEPTIONS}>")

target_compile_features(${PROJECT_NAME}
        PUBLIC
        cxx_std_17
)

# These compiler options reflect what is in godot/SConstruct.
target_compile_options( ${PROJECT_NAME}
PUBLIC
    # MSVC only
    $<${IS_MSVC}:
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
        $<${WARNING_AS_ERROR}:/WX>
    >
PRIVATE

    # Clang and GNU common options
    $<$<OR:${IS_CLANG},${IS_GNU}>:
        -Wall
        -Wctor-dtor-privacy
        -Wextra
        -Wno-unused-parameter
        -Wnon-virtual-dtor
        -Wwrite-strings

        $<${WARNING_AS_ERROR}:-Werror>
    >

    # Clang only
    $<${IS_CLANG}:
        -Wimplicit-fallthrough
        -Wno-ordered-compare-function-pointers
    >

    # GNU only
    $<${IS_GNU}:
        -Walloc-zero
        -Wduplicated-branches
        -Wduplicated-cond
        -Wno-misleading-indentation
        -Wplacement-new=1
        -Wshadow-local
        -Wstringop-overflow=4

        # Bogus warning fixed in 8+.
        $<${GNU_LT_V8}:-Wno-strict-overflow>

        $<${GNU_GE_V9}:-Wattribute-alias=2>

        # Broke on MethodBind templates before GCC 11.
        $<${GNU_GT_V11}:-Wlogical-op>

        # Regression in GCC 9/10, spams so much in our variadic templates that we need to outright disable it.
        $<${GNU_LT_V11}:-Wno-type-limits>

        # False positives in our error macros, see GH-58747.
        $<${GNU_GE_V12}:-Wno-return-type>
    >
PUBLIC
    $<${IS_MSVC}:
        /utf-8
        $<IF:$<CONFIG:Debug>,/MDd,/MD /O2>
        $<$<NOT:${DISABLE_EXCEPTIONS}>:/EHsc>
    >

    $<$<OR:${IS_CLANG},${IS_GNU}>:
        $<${DISABLE_EXCEPTIONS}:-fno-exceptions>

        $<IF:$<CONFIG:Debug>,-fno-omit-frame-pointer -O0 -g,-O3>
    >
    $<${IS_GNU}:$<${HOT_RELOAD}:-fno-gnu-unique>>
)

target_compile_definitions(${PROJECT_NAME}
        PUBLIC
        GDEXTENSION

        $<$<BOOL:${WIN32}>:WINDOWS_ENABLED>

        $<${IS_MSVC}:
            TYPED_METHOD_BIND
            NOMINMAX
            $<${DISABLE_EXCEPTIONS}:_HAS_EXCEPTIONS=0>
        >

        $<IF:$<CONFIG:Debug>,DEBUG_ENABLED DEBUG_METHODS_ENABLED,NDEBUG>

        $<${HOT_RELOAD}:HOT_RELOAD_ENABLED>

        $<$<STREQUAL:${GODOT_PRECISION},double>:REAL_T_IS_DOUBLE>
)

target_link_options(${PROJECT_NAME} PRIVATE
    $<$<OR:${IS_CLANG},${IS_GNU}>:
        -static-libgcc
        -static-libstdc++
    >

    $<$<PLATFORM_ID:Linux>:
        $<${IS_GNU}:
            -Wl,-R,'$$ORIGIN'
        >
    >
)
