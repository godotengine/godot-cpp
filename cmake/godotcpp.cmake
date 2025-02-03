#[=======================================================================[.rst:
godotcpp.cmake
--------------

As godot-cpp is a C++ project, there are no C files, and detection of a C
compiler is unnecessary. When CMake performs the configure process, if a
C compiler is specified, like in a toolchain, or from an IDE, then it will
print a warning stating that the CMAKE_C_COMPILER compiler is unused.
This if statement simply silences that warning.
]=======================================================================]
if( CMAKE_C_COMPILER )
endif ()

#[=======================================================================[.rst:
Include Platform Files
----------------------

Because these files are included into the top level CMakelists.txt before the
project directive, it means that

* ``CMAKE_CURRENT_SOURCE_DIR`` is the location of godot-cpp's CMakeLists.txt
* ``CMAKE_SOURCE_DIR`` is the location where any prior ``project(...)``
  directive was

]=======================================================================]
include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake/common_compiler_flags.cmake)
include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake/android.cmake)
include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ios.cmake)
include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake/linux.cmake)
include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake/macos.cmake)
include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake/web.cmake)
include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake/windows.cmake)
include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake/python_callouts.cmake)

# Detect number of processors
include(ProcessorCount)
ProcessorCount(PROC_MAX)
message( "Auto-detected ${PROC_MAX} CPU cores available for build parallelism." )

# List of known platforms
set( PLATFORM_LIST linux macos windows android ios web )

# List of known architectures
set( ARCH_LIST universal x86_32 x86_64 arm32 arm64 rv64 ppc32 ppc64 wasm32 )

# Function to map processors to known architectures
function( godot_arch_map ALIAS PROC )
    string( TOLOWER "${PROC}" PROC )

    if( "${PROC}" IN_LIST ARCH_LIST )
        set( ${ALIAS} "${PROC}" PARENT_SCOPE)
        return()
    endif()

    set( x86_64 "w64;amd64" )
    set( arm32  "armv7" )
    set( arm64  "armv8;arm64v8;aarch64" )
    set( rv64   "rv;riscv;riscv64" )
    set( ppc32  "ppcle;ppc" )
    set( ppc64  "ppc64le" )

    if( PROC IN_LIST x86_64  )
        set(${ALIAS} "x86_64" PARENT_SCOPE )

    elseif( PROC IN_LIST arm32 )
        set(${ALIAS} "arm32" PARENT_SCOPE )

    elseif( PROC IN_LIST arm64 )
        set(${ALIAS} "arm64" PARENT_SCOPE )

    elseif( PROC IN_LIST rv64 )
        set(${ALIAS} "rv64" PARENT_SCOPE )

    elseif( PROC IN_LIST ppc32 )
        set(${ALIAS} "ppc32" PARENT_SCOPE )

    elseif( PROC IN_LIST ppc64 )
        set(${ALIAS} "ppc64" PARENT_SCOPE )

    else()
        set(${ALIAS} "unknown" PARENT_SCOPE )
    endif ()
endfunction()

# Function to define all the options.
function( godotcpp_options )
    #NOTE: platform is managed using toolchain files.

    # Input from user for GDExtension interface header and the API JSON file
    set(GODOT_GDEXTENSION_DIR "gdextension" CACHE PATH
            "Path to a custom directory containing GDExtension interface header and API JSON file ( /path/to/gdextension_dir )" )
    set(GODOT_CUSTOM_API_FILE "" CACHE FILEPATH
            "Path to a custom GDExtension API JSON file (takes precedence over `GODOT_GDEXTENSION_DIR`) ( /path/to/custom_api_file )")

    #TODO generate_bindings

    option(GODOT_GENERATE_TEMPLATE_GET_NODE
            "Generate a template version of the Node class's get_node. (ON|OFF)" ON)

    #TODO build_library

    set(GODOT_PRECISION "single" CACHE STRING
            "Set the floating-point precision level (single|double)")

    # The arch is typically set by the toolchain
    # however for Apple multi-arch setting it here will override.
    set( GODOT_ARCH "" CACHE STRING "Target CPU Architecture")
    set_property( CACHE GODOT_ARCH PROPERTY STRINGS ${ARCH_LIST} )

    #TODO threads
    #TODO compiledb
    #TODO compiledb_file

    set( GODOT_BUILD_PROFILE "" CACHE PATH
            "Path to a file containing a feature build profile" )

    set(GODOT_USE_HOT_RELOAD "" CACHE BOOL
            "Enable the extra accounting required to support hot reload. (ON|OFF)")

    # Disable exception handling. Godot doesn't use exceptions anywhere, and this
    # saves around 20% of binary size and very significant build time (GH-80513).
    option(GODOT_DISABLE_EXCEPTIONS "Force disabling exception handling code (ON|OFF)" ON )

    set( GODOT_SYMBOL_VISIBILITY "hidden" CACHE STRING
            "Symbols visibility on GNU platforms. Use 'auto' to apply the default value. (auto|visible|hidden)")
    set_property( CACHE GODOT_SYMBOL_VISIBILITY PROPERTY STRINGS "auto;visible;hidden" )

    #TODO optimize

    option( GODOT_DEV_BUILD "Developer build with dev-only debugging code (DEV_ENABLED)" OFF )

    #[[ debug_symbols
    Debug symbols are enabled by using the Debug or RelWithDebInfo build configurations.
    Single Config Generator is set at configure time

        cmake ../ -DCMAKE_BUILD_TYPE=Debug

    Multi-Config Generator is set at build time

        cmake --build . --config Debug

    ]]

    # FIXME These options are not present in SCons, and perhaps should be added there.
    option( GODOT_SYSTEM_HEADERS "Expose headers as SYSTEM." OFF )
    option( GODOT_WARNING_AS_ERROR "Treat warnings as errors" OFF )

    # Enable Testing
    option( GODOT_ENABLE_TESTING "Enable the godot-cpp.test.<target> integration testing targets" OFF )

    #[[ Target Platform Options ]]
    android_options()
    ios_options()
    linux_options()
    macos_options()
    web_options()
    windows_options()
endfunction()

# Function to configure and generate the targets
function( godotcpp_generate )
    #[[ Multi-Threaded MSVC Compilation
    When using the MSVC compiler the build command -j <n> only specifies
    parallel jobs or targets, and not multi-threaded compilation To speed up
    compile times on msvc, the /MP <n> flag can be set. But we need to set it
    at configure time.

    MSVC is true when the compiler is some version of Microsoft Visual C++ or
    another compiler simulating the Visual C++ cl command-line syntax. ]]
    if( MSVC )
        math( EXPR PROC_N "(${PROC_MAX}-1) | (${X}-2)>>31 & 1" )
        message( "Using ${PROC_N} cores for multi-threaded compilation.")
        # TODO You can override it at configure time with ...." )
    else ()
        message( "Using ${CMAKE_BUILD_PARALLEL_LEVEL} cores, You can override"
        " it at configure time by using -j <n> or --parallel <n> on the build"
        " command.")
        message( "  eg. cmake --build . -j 7  ...")
    endif ()

    #[[ GODOT_SYMBOL_VISIBLITY
    To match the SCons options, the allowed values are "auto", "visible", and "hidden"
    This effects the compiler flag_ -fvisibility=[default|internal|hidden|protected]
    The corresponding target option CXX_VISIBILITY_PRESET accepts the compiler values.

    TODO: It is probably worth a pull request which changes both to use the compiler values
    .. _flag:https://gcc.gnu.org/onlinedocs/gcc/Code-Gen-Options.html#index-fvisibility
    ]]
    if( ${GODOT_SYMBOL_VISIBILITY} STREQUAL "auto" OR ${GODOT_SYMBOL_VISIBILITY} STREQUAL "visible" )
        set( GODOT_SYMBOL_VISIBILITY "default" )
    endif ()

    # Setup variable to optionally mark headers as SYSTEM
    set(GODOT_SYSTEM_HEADERS_ATTRIBUTE "")
    if (GODOT_SYSTEM_HEADERS)
        set(GODOT_SYSTEM_HEADERS_ATTRIBUTE SYSTEM)
    endif ()

    #[[ Configure Binding Variables ]]
    # Generate Binding Parameters (True|False)
    set( USE_TEMPLATE_GET_NODE "False" )
    if( GODOT_GENERATE_TEMPLATE_GET_NODE )
        set( USE_TEMPLATE_GET_NODE "True" )
    endif()

    # Bits (32|64)
    math( EXPR BITS "${CMAKE_SIZEOF_VOID_P} * 8" ) # CMAKE_SIZEOF_VOID_P refers to target architecture.

    # API json File
    set(GODOT_GDEXTENSION_API_FILE "${GODOT_GDEXTENSION_DIR}/extension_api.json")
    if( GODOT_CUSTOM_API_FILE )  # User-defined override.
        set(GODOT_GDEXTENSION_API_FILE "${GODOT_CUSTOM_API_FILE}")
    endif()

    # Build Profile
    if( GODOT_BUILD_PROFILE )
        message( STATUS "Using build profile to trim api file")
        message(  "\tBUILD_PROFILE = '${GODOT_BUILD_PROFILE}'")
        message(  "\tAPI_SOURCE = '${GODOT_GDEXTENSION_API_FILE}'")
        build_profile_generate_trimmed_api(
                "${GODOT_BUILD_PROFILE}"
                "${GODOT_GDEXTENSION_API_FILE}"
                "${CMAKE_CURRENT_BINARY_DIR}/extension_api.json" )
        set( GODOT_GDEXTENSION_API_FILE "${CMAKE_CURRENT_BINARY_DIR}/extension_api.json" )
    endif()

    message( STATUS "GODOT_GDEXTENSION_API_FILE = '${GODOT_GDEXTENSION_API_FILE}'")

    # generate the file list to use
    binding_generator_get_file_list( GENERATED_FILES_LIST
            "${GODOT_GDEXTENSION_API_FILE}"
            "${CMAKE_CURRENT_BINARY_DIR}" )

    binding_generator_generate_bindings(
            "${GODOT_GDEXTENSION_API_FILE}"
            "${USE_TEMPLATE_GET_NODE}"
            "${BITS}"
            "${GODOT_PRECISION}"
            "${CMAKE_CURRENT_BINARY_DIR}" )

    ### Platform is derived from the toolchain target
    # See GeneratorExpressions PLATFORM_ID and CMAKE_SYSTEM_NAME
    string( APPEND SYSTEM_NAME
            "$<$<PLATFORM_ID:Android>:android.${ANDROID_ABI}>"
            "$<$<PLATFORM_ID:iOS>:ios>"
            "$<$<PLATFORM_ID:Linux>:linux>"
            "$<$<PLATFORM_ID:Darwin>:macos>"
            "$<$<PLATFORM_ID:Emscripten>:web>"
            "$<$<PLATFORM_ID:Windows>:windows>"
            "$<$<PLATFORM_ID:Msys>:windows>"
    )

    ### Use the arch from the toolchain if it isn't set manually
    if( GODOT_ARCH )
        set(SYSTEM_ARCH ${GODOT_ARCH})
    else()
        godot_arch_map( SYSTEM_ARCH ${CMAKE_SYSTEM_PROCESSOR} )
    endif()

    # Transform options into generator expressions
    set( HOT_RELOAD-UNSET "$<STREQUAL:${GODOT_USE_HOT_RELOAD},>")

    set( DISABLE_EXCEPTIONS "$<BOOL:${GODOT_DISABLE_EXCEPTIONS}>")

    # GODOT_DEV_BUILD
    set( RELEASE_TYPES "Release;MinSizeRel")
    get_property( IS_MULTI_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG )
    if( IS_MULTI_CONFIG )
        message( NOTICE "=> Default build type is Debug. For other build types add --config <type> to build command")
    elseif( GODOT_DEV_BUILD AND CMAKE_BUILD_TYPE IN_LIST RELEASE_TYPES )
        message( WARNING "=> GODOT_DEV_BUILD implies a Debug-like build but CMAKE_BUILD_TYPE is '${CMAKE_BUILD_TYPE}'")
    endif ()
    set( IS_DEV_BUILD "$<BOOL:${GODOT_DEV_BUILD}>")
    # The .dev portion of the name if GODOT_DEV_BUILD is true.
    set( DEV_TAG "$<${IS_DEV_BUILD}:.dev>" )

    ### Define our godot-cpp library targets
    foreach ( TARGET_ALIAS template_debug template_release editor )
        set( TARGET_NAME "godot-cpp.${TARGET_ALIAS}" )

        # Generator Expressions that rely on the target
        set( DEBUG_FEATURES "$<NOT:$<STREQUAL:${TARGET_ALIAS},template_release>>" )
        set( HOT_RELOAD "$<IF:${HOT_RELOAD-UNSET},${DEBUG_FEATURES},$<BOOL:${GODOT_USE_HOT_RELOAD}>>" )

        # the godot-cpp.* library targets
        add_library( ${TARGET_NAME} STATIC EXCLUDE_FROM_ALL )
        add_library( godot-cpp::${TARGET_ALIAS} ALIAS ${TARGET_NAME} )

        file( GLOB_RECURSE GODOTCPP_SOURCES LIST_DIRECTORIES NO CONFIGURE_DEPENDS src/*.cpp )

        target_sources( ${TARGET_NAME}
                PRIVATE
                ${GODOTCPP_SOURCES}
                ${GENERATED_FILES_LIST}
        )

        target_include_directories( ${TARGET_NAME} ${GODOT_SYSTEM_HEADERS_ATTRIBUTE} PUBLIC
                include
                ${CMAKE_CURRENT_BINARY_DIR}/gen/include
                ${GODOT_GDEXTENSION_DIR}
        )

        set_target_properties( ${TARGET_NAME}
                PROPERTIES
                CXX_STANDARD 17
                CXX_EXTENSIONS OFF
                CXX_VISIBILITY_PRESET ${GODOT_SYMBOL_VISIBILITY}

                COMPILE_WARNING_AS_ERROR ${GODOT_WARNING_AS_ERROR}
                POSITION_INDEPENDENT_CODE ON
                BUILD_RPATH_USE_ORIGIN ON

                PREFIX lib
                OUTPUT_NAME "${PROJECT_NAME}.${SYSTEM_NAME}.${TARGET_ALIAS}${DEV_TAG}.${SYSTEM_ARCH}"
                ARCHIVE_OUTPUT_DIRECTORY "$<1:${CMAKE_BINARY_DIR}/bin>"

                # Things that are handy to know for dependent targets
                GODOT_PLATFORM "${SYSTEM_NAME}"
                GODOT_TARGET "${TARGET_ALIAS}"
                GODOT_ARCH "${SYSTEM_ARCH}"

                # Some IDE's respect this property to logically group targets
                FOLDER "godot-cpp"
        )

        if( CMAKE_SYSTEM_NAME STREQUAL Android )
            android_generate()
        elseif ( CMAKE_SYSTEM_NAME STREQUAL iOS )
            ios_generate()
        elseif ( CMAKE_SYSTEM_NAME STREQUAL Linux )
            linux_generate()
        elseif ( CMAKE_SYSTEM_NAME STREQUAL Darwin )
            macos_generate()
        elseif ( CMAKE_SYSTEM_NAME STREQUAL Emscripten )
            web_generate()
        elseif ( CMAKE_SYSTEM_NAME STREQUAL Windows )
            windows_generate()
        endif ()

    endforeach ()

    # Added for backwards compatibility with prior cmake solution so that builds dont immediately break
    # from a missing target.
    add_library( godot::cpp ALIAS godot-cpp.template_debug )

endfunction()
