#[=======================================================================[.rst:
Ios
---

This file contains functions for options and configuration for targeting the
Ios platform

]=======================================================================]

#[==============================[ iOS Options ]==============================]
function(ios_options)
#    TODO "ios_simulator", "Target iOS Simulator", False
#    TODO "ios_min_version", "Target minimum iphoneos/iphonesimulator version", "12.0"
#    TODO "IOS_TOOLCHAIN_PATH",
#        "Path to iOS toolchain",
#        "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain",
#    TODO "IOS_SDK_PATH", "Path to the iOS SDK", ""
#
#    TODO if has_ios_osxcross(): "ios_triple", "Triple for ios toolchain", ""
endfunction()

#[===========================[ Target Generation ]===========================]
function(ios_generate)
    target_compile_definitions(${TARGET_NAME}
            PUBLIC
            IOS_ENABLED
            UNIX_ENABLED
    )

    common_compiler_flags()
endfunction()
