#[=======================================================================[.rst:
Android
-------

This file contains functions for options and configuration for targeting the
Android platform

Configuration of the Android toolchain is done using toolchain files,
CMakePresets, or variables on the command line.

The `Android SDK`_ provides toolchain files to help with configuration.

CMake has its own `built-in support`_ for cross compiling to the
Android platforms.

.. warning::

    Android does not support or test the CMake built-in workflow, recommend
    using their toolchain file.

.. _Android SDK:https://developer.android.com/ndk/guides/cmake

.. _built-in support:https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#cross-compiling-for-android

There is further information and examples in the doc/cmake.rst file.

]=======================================================================]

#[============================[ Android Options ]============================]
function( android_options )
    #[[ The options present in the SCons build shown below are managed by
    toolchain files, further information can be found in doc/cmake.rst

    android_api_level : Target Android API level.
        Default = 21

    ANDROID_HOME : Path to your Android SDK installation.
        Default = os.environ.get("ANDROID_HOME", os.environ.get("ANDROID_SDK_ROOT")
    ]]
endfunction()

#[===========================[ Target Generation ]===========================]
function( android_generate )
    target_compile_definitions(${TARGET_NAME}
            PUBLIC
            ANDROID_ENABLED
            UNIX_ENABLED
    )

    common_compiler_flags()
endfunction()
