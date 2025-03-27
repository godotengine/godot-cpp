#[=======================================================================[.rst:

msvcHack.cmake
--------------

There are a couple of things that CMake does which mess up the build and are
hard to work around. This cmake script is an attempt to document and work
around those shortcomings.

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

it is stated in the msvc_ documentation that: "All modules passed to a given
invocation of the linker must have been compiled with the same runtime library
compiler option (/MD, /MT, /LD)."

This creates a conundrum for us, the ``CMAKE_MSVC_RUNTIME_LIBRARY`` needs to be
correct at the time the target is created, but we have no control over the
consumers CMake scripts, and the per-target ``MSVC_RUNTIME_LIBRARY`` property
is not transient.

It has been raised that not using ``CMAKE_MSVC_RUNTIME_LIBRARY`` can also cause
issues_ when a dependency( independent to godot-cpp ) that doesn't set any
runtime flags, which relies purely on the ``CMAKE_MSVC_RUNTIME_LIBRARY``
variable will very likely not have the correct msvc runtime flags set.

So we'll set ``CMAKE_MSVC_RUNTIME_LIBRARY`` as CACHE STRING so that it will be
available for consumer target definitions, but also be able to be overridden if
needed.

Additionally we message consumers notifying them and pointing to this
documentation.

.. _CMP0091:https://cmake.org/cmake/help/latest/policy/CMP0091.html
.. _property:https://cmake.org/cmake/help/latest/variable/CMAKE_MSVC_RUNTIME_LIBRARY.html
.. https://discourse.cmake.org/t/mt-staticrelease-doesnt-match-value-md-dynamicrelease/5428/4
.. _msvc: https://learn.microsoft.com/en-us/cpp/build/reference/md-mt-ld-use-run-time-library
.. _issues: https://github.com/godotengine/godot-cpp/issues/1699

Run-Time Error Checks
---------------------

The MSVC compiler flag_ /RTC[] is Used to enable and disable the run-time error
checks feature, in conjunction with the runtime_checks pragma.

.. _flag: https://learn.microsoft.com/en-us/cpp/build/reference/rtc-run-time-error-checks?view=msvc-170

If enabled it triggers a stacktrace when a template_debug godot loads an
gdextension. Unfortunately CMake adds this flag to Debug builds, and there
is no simple solution for removing it. The solution here, is drawn from
others experiences 1_, 2_.

.. _1: https://discourse.cmake.org/t/how-do-i-remove-compile-options-from-target/5965
.. _2: https://stackoverflow.com/questions/74426638/how-to-remove-rtc1-from-specific-target-or-file-in-cmake

There are two locations where the RTC options appear, and they are both within
the same macro in the file_: Platform/Windows-MSVC.cmake

.. _file: https://gitlab.kitware.com/cmake/cmake/-/blob/566e96d42db35e2c88ceb5d0f3de49736295c496/Modules/Platform/Windows-MSVC.cmake

FUTURE: CMake introduced the ``CMAKE_MSVC_RUNTIME_CHECKS`` option_ in v4.0
.. _option: https://cmake.org/cmake/help/latest/variable/CMAKE_MSVC_RUNTIME_CHECKS.html

]=======================================================================]

if(MSVC)
    message(
        STATUS
        "NOTE: We know its bad etiquette to set global build variables, however,\n"
        "\tCMAKE_MSVC_RUNTIME_LIBRARY needs to be set to something specific for godot-cpp, and\n"
        "\tCMAKE_CXX_FLAGS_DEBUG needs /RTC1 removed as it triggers a segfaut on when template_debug loads\n"
        "\tPlease ensure that any targets that are linking with godot-cpp are defined after godot-cpp\n"
        "\tFor more information please read godot-cpp/cmake/msvcHack.cmake"
    )

    if(CMAKE_VS_PLATFORM_TOOLSET MATCHES "v[0-9]+_clang_.*") # The same condition that Windows-MSVC.cmake uses
    else()
        string(REPLACE "/RTC1" "" CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}")
        string(REPLACE "/RTC1" "" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
    endif()

    set(CMAKE_MSVC_RUNTIME_LIBRARY
        "MultiThreaded$<IF:$<BOOL:${GODOTCPP_DEBUG_CRT}>,DebugDLL,$<$<NOT:$<BOOL:${GODOTCPP_USE_STATIC_CPP}>>:DLL>>"
        CACHE STRING
        "Select the MSVC runtime library for use by compilers targeting the MSVC ABI."
    )
endif()
