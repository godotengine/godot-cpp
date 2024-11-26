CMake
=====

.. warning::

    The CMake scripts do not have feature parity with the SCons ones at this
    stage and are still a work in progress. There are a number of people who
    have been working on alternative CMake solutions that are frequently
    referenced in the discord chats: Ivan's cmake-rewrite_ branch and
    Vorlac's godot-roguelite_ Project

.. _cmake-rewrite: https://github.com/IvanInventor/godot-cpp/tree/cmake-rewrite
.. _godot-roguelite: https://github.com/vorlac/godot-roguelite

Introduction
------------

Compiling godot-cpp independently of an extension project is mainly for
godot-cpp developers, package maintainers, and CI/CD. Look to the
godot-cpp-template_ for a practical example on how to consume the godot-cpp
library as part of a Godot extension.

Configuration examples are listed at the bottom of the page.

.. _godot-cpp-template: https://github.com/godotengine/godot-cpp-template

SCons Deviations
----------------

Not everything from SCons can be perfectly representable in CMake, here are
the notable differences.

- debug_symbols
    No longer has an explicit option, and is enabled via Debug-like CMake
    build configurations; Debug, RelWithDebInfo.

- dev_build
    Does not define NDEBUG when disabled, NDEBUG is set via Release-like
    CMake build configurations; Release, MinSizeRel.

Basic walkthrough
-----------------

.. topic:: Clone the git repository

    .. code-block::

        git clone https://github.com/godotengine/godot-cpp.git
        Cloning into 'godot-cpp'...
        ...
        cd godot-cpp


.. topic:: Out-of-tree build directory

    Create a build directory for CMake to put caches and build artifacts in and
    change directory to it. This is typically as a sub-directory of the project
    root but can be outside the source tree. This is so that generated files do
    not clutter up the source tree.

    .. code-block::

        mkdir cmake-build
        cd cmake-build

.. topic:: Configure the build

    CMake doesn't build the code, it generates the files that another tool uses
    to build the code. To see the list of generators run ``cmake --help``. The
    first phase of which is running through the configuration scripts.

    Configure and generate Ninja build files.

    .. code-block::

        cmake ../ -G "Ninja"

    To list the available options CMake use the ``-L[AH]`` option. ``A`` is for
    advanced, and ``H`` is for help strings.

    .. code-block::

        cmake ../ -LH

    Options are specified on the command line when configuring

    .. code-block::

        cmake ../ -DGODOT_USE_HOT_RELOAD:BOOL=ON \
            -DGODOT_PRECISION:STRING=double \
            -DCMAKE_BUILD_TYPE:STRING=Debug

    Review setting-build-variables_ and build-configurations_ for more information.

    .. _setting-build-variables: https://cmake.org/cmake/help/latest/guide/user-interaction/index.html#setting-build-variables
    .. _build-configurations: https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#build-configurations

    A non-exhaustive list of options:

    .. code-block::

        // Path to a custom GDExtension API JSON file (takes precedence over `GODOT_GDEXTENSION_DIR`) ( /path/to/custom_api_file )
        `GODOT_CUSTOM_API_FILE:FILEPATH=`

        // Force disabling exception handling code (ON|OFF)
        GODOT_DISABLE_EXCEPTIONS:BOOL=ON

        // Path to a custom directory containing GDExtension interface header and API JSON file ( /path/to/gdextension_dir )
        GODOT_GDEXTENSION_DIR:PATH=gdextension

        // Generate a template version of the Node class's get_node. (ON|OFF)
        GODOT_GENERATE_TEMPLATE_GET_NODE:BOOL=ON

        // Set the floating-point precision level (single|double)
        GODOT_PRECISION:STRING=single

        // Symbols visibility on GNU platforms. Use 'auto' to apply the default value. (auto|visible|hidden)
        GODOT_SYMBOL_VISIBILITY:STRING=hidden

        // Expose headers as SYSTEM.
        GODOT_SYSTEM_HEADERS:BOOL=ON

        // Enable the extra accounting required to support hot reload. (ON|OFF)
        GODOT_USE_HOT_RELOAD:BOOL=

        // Treat warnings as errors
        GODOT_WARNING_AS_ERROR:BOOL=OFF


.. topic:: Compiling

   A target and a configuration is required, as the default ``all`` target does
   not include anything and when using multi-config generators like ``Ninja
   Multi-Config``, ``Visual Studio *`` or ``Xcode`` the build configuration
   needs to be specified at build time. Build in Release mode unless you need
   debug symbols.

    .. code-block::

        cmake --build . -t template_debug --config Release

Examples
--------

Windows and MSVC
~~~~~~~~~~~~~~~~
So long as CMake is installed from the `CMake Downloads`_ page and in the PATH,
and Microsoft Visual Studio is installed with c++ support, CMake will detect
the MSVC compiler.

.. _CMake downloads: https://cmake.org/download/

Assuming the current working directory is the godot-cpp project root:

.. code-block::

    mkdir build-msvc
    cd build-msvc
    cmake ../
    cmake --build . -t godot-cpp-test --config Release


MSys2/clang64, "Ninja", godot-cpp-test target with debug symbols
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Assumes the ming-w64-clang-x86_64-toolchain is installed

Using the msys2/clang64 shell

.. code-block::

    mkdir build-clang
    cd build-clang
    cmake ../ -G"Ninja" -DCMAKE_BUILD_TYPE:STRING=Debug
    cmake --build . -t godot-cpp-test

MSys2/clang64, "Ninja Multi-Config", godot-cpp-test target with GODOT_DEV_BUILD
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Assumes the ming-w64-clang-x86_64-toolchain is installed

Using the msys2/clang64 shell

.. code-block::

    mkdir build-clang
    cd build-clang
    cmake ../ -G"Ninja Multi-Config" -DGODOT_DEV_BUILD:BOOL=ON
    cmake --build . -t godot-cpp-test --config Debug

Emscripten for web, template_release target
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
I've only tested this on windows so far.

I cloned, installed, and activating the latest Emscripten tools(for me it was
3.1.69) to ``c:\emsdk``

From a terminal running the ``c:\emsdk\emcmdprompt.bat`` puts me in a cmdprompt
context which I dislike, so after that I run pwsh to get my powershell 7.4.5
context back.

using the ``emcmake.bat`` command adds the emscripten toolchain to the CMake
command

.. code-block::

    C:\emsdk\emcmdprompt.bat
    pwsh
    cd <godot-cpp source folder>
    mkdir build-wasm32
    cd build-wasm32
    emcmake.bat cmake ../
    cmake --build . --verbose -t template_release

Android Cross Compile from Windows
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
There are two separate paths you can choose when configuring for android.

Use the ``CMAKE_ANDROID_*`` variables specified on the commandline or in your
own toolchain file as listed in the cmake-toolchains_ documentation

.. _cmake-toolchains: https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#cross-compiling-for-android-with-the-ndk

Or use the toolchain and scripts provided by the Android SDK and make changes
using the ``ANDROID_*`` variables listed there. Where ``<version>`` is whatever
ndk version you have installed ( tested with `23.2.8568313`) and ``<platform>``
is for android sdk platform, (tested with ``android-29``)

.. warning::

    The Android SDK website explicitly states that they do not support using
    the CMake built-in method, and recommends you stick with their toolchain
    files.

.. topic:: Using your own toolchain file as described in the CMake documentation

    .. code-block::

        mkdir build-android
        cd build-android
        cmake ../ --toolchain my_toolchain.cmake
        cmake --build . -t template_release

    Doing the equivalent on just using the command line

    .. code-block::

        mkdir build-android
        cd build-android
        cmake ../ \
            -DCMAKE_SYSTEM_NAME=Android \
            -DCMAKE_SYSTEM_VERSION=<platform> \
            -DCMAKE_ANDROID_ARCH_ABI=<arch> \
            -DCMAKE_ANDROID_NDK=/path/to/android-ndk
        cmake --build . -t template_release

.. topic:: Using the toolchain file from the Android SDK

    Defaults to minimum supported version( android-16 in my case) and armv7-a.

    .. code-block::

        mkdir build-android
        cd build-android
        cmake ../ --toolchain $ANDROID_HOME/ndk/<version>/build/cmake/android.toolchain.cmake
        cmake --build . -t template_release

    Specify Android platform and ABI

    .. code-block::

        mkdir build-android
        cd build-android
        cmake ../ --toolchain $ANDROID_HOME/ndk/<version>/build/cmake/android.toolchain.cmake \
          -DANDROID_PLATFORM:STRING=android-29 \
          -DANDROID_ABI:STRING=armeabi-v7a
        cmake --build . -t template_release


Toolchains
----------
This section attempts to list the host and target combinations that have been
at tested.

Info on cross compiling triplets indicates that the naming is a little more
freeform that expected, and tailored to its use case. Triplets tend to have the
format ``<arch>[sub][-vendor][-OS][-env]``

* `osdev.org <https://wiki.osdev.org/Target_Triplet>`_
* `stack overflow <https://stackoverflow.com/questions/13819857/does-a-list-of-all-known-target-triplets-in-use-exist>`_
* `LLVM <https://llvm.org/doxygen/classllvm_1_1Triple.html>`_
* `clang target triple <https://clang.llvm.org/docs/CrossCompilation.html#target-triple>`_
* `vcpkg <https://learn.microsoft.com/en-us/vcpkg/concepts/triplets>`_
* `wasm32-unknown-emscripten <https://blog.therocode.net/2020/10/a-guide-to-rust-sdl2-emscripten>`_

Linux Host
~~~~~~~~~~

:Target: x86_64-linux

Macos Host
~~~~~~~~~~

:System: Mac Mini
:OS Name: Sequoia 15.0.1
:Processor: Apple M2

Windows Host
~~~~~~~~~~~~

:OS Name: Microsoft Windows 11 Home, 10.0.22631 N/A Build 22631
:Processor: AMD Ryzen 7 6800HS Creator Edition

`Microsoft Visual Studio 17 2022 <https://visualstudio.microsoft.com/vs/>`_
    :Target: x86_64-w64

`LLVM <https://llvm.org/>`_
    :Target: x86_64-pc-windows-msvc

`AndroidSDK <https://developer.android.com/studio/#command-tools>`_
    armv7-none-linux-androideabi16

`Emscripten <https://emscripten.org/>`_
    :Compiler: Emscripten
    :Target: wasm32-unknown-emscripten

`MinGW-w64 <https://www.mingw-w64.org/>`_ based toolchains

    `MSYS2 <https://www.msys2.org/>`_
        Necessary reading about MSYS2 `environments <https://www.msys2.org/docs/environments/>`_

        ucrt64
            :Compiler: gcc version 14.2.0 (Rev1, Built by MSYS2 project)
            :Target:   x86_64-w64-mingw32

        clang64
            :Compiler: clang version 18.1.8
            :Target:   x86_64-w64-windows-gnu

    `LLVM-MinGW <https://github.com/mstorsjo/llvm-mingw/releases>`_

    `MinGW-W64-builds <https://github.com/niXman/mingw-builds-binaries/releases>`_
        :Compiler: gcc
        :Target: x86_64-w64-mingw32-ucrt

    `Jetbrains-CLion <https://www.jetbrains.com/clion/>`_
        :Target: x86_64-w64-mingw32-msvcrt
