function( godotcpp_options )

    #TODO platform
    #TODO target

    # Input from user for GDExtension interface header and the API JSON file
    set(GODOT_GDEXTENSION_DIR "gdextension" CACHE PATH
            "Path to a custom directory containing GDExtension interface header and API JSON file ( /path/to/gdextension_dir )" )
    set(GODOT_CUSTOM_API_FILE "" CACHE FILEPATH
            "Path to a custom GDExtension API JSON file (takes precedence over `gdextension_dir`) ( /path/to/custom_api_file )")

    #TODO generate_bindings

    option(GODOT_GENERATE_TEMPLATE_GET_NODE
            "Generate a template version of the Node class's get_node. (ON|OFF)" ON)

    #TODO build_library

    set(GODOT_PRECISION "single" CACHE STRING
            "Set the floating-point precision level (single|double)")

    #TODO arch
    #TODO threads
    #TODO compiledb
    #TODO compiledb_file
    #TODO build_profile aka cmake preset

    set(GODOT_USE_HOT_RELOAD "" CACHE BOOL
            "Enable the extra accounting required to support hot reload. (ON|OFF)")

    option(GODOT_DISABLE_EXCEPTIONS "Force disabling exception handling code (ON|OFF)" ON )

    set( GODOT_SYMBOL_VISIBILITY "hidden" CACHE STRING
            "Symbols visibility on GNU platforms. Use 'auto' to apply the default value. (auto|visible|hidden)")
    set_property( CACHE GODOT_SYMBOL_VISIBILITY PROPERTY STRINGS "auto;visible;hidden" )

    #TODO optimize
    #TODO debug_symbols
    #TODO dev_build

    # FIXME These options are not present in SCons, and perhaps should be added there.
    option(GODOT_SYSTEM_HEADERS "Expose headers as SYSTEM." ON)
    option(GODOT_WARNING_AS_ERROR "Treat warnings as errors" OFF)

    # Run options commands on the following to populate cache for all platforms.
    # This type of thing is typically done conditionally
    # But as scons shows all options so shall we.
    #TODO ios_options()
    #TODO linux_options()
    #TODO macos_options()
    #TODO web_options()
    #TODO windows_options()
endfunction()


function( godotcpp_generate )
    # Set some helper variables for readability
    set( compiler_is_clang "$<OR:$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:Clang>>" )
    set( compiler_is_gnu "$<CXX_COMPILER_ID:GNU>" )
    set( compiler_is_msvc "$<CXX_COMPILER_ID:MSVC>" )

    # CXX_VISIBILITY_PRESET supported values are: default, hidden, protected, and internal
    # which is inline with the gcc -fvisibility=
    # https://gcc.gnu.org/onlinedocs/gcc/Code-Gen-Options.html
    # To match the scons options we need to change the text to match the -fvisibility flag
    # it is probably worth another PR which changes both to use the flag options
    if( ${GODOT_SYMBOL_VISIBILITY} STREQUAL "auto" OR ${GODOT_SYMBOL_VISIBILITY} STREQUAL "visible" )
        set( GODOT_SYMBOL_VISIBILITY "default" )
    endif ()

    # Default build type is Debug in the SConstruct
    if("${CMAKE_BUILD_TYPE}" STREQUAL "")
        set(CMAKE_BUILD_TYPE Debug)
    endif()

    # Hot reload is enabled by default in Debug-builds
    if( GODOT_USE_HOT_RELOAD STREQUAL "" AND NOT CMAKE_BUILD_TYPE STREQUAL "Release")
        set(GODOT_USE_HOT_RELOAD ON)
    endif()

    if(NOT DEFINED BITS)
        set(BITS 32)
        if(CMAKE_SIZEOF_VOID_P EQUAL 8)
            set(BITS 64)
        endif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    endif()


    set(GODOT_GDEXTENSION_API_FILE "${GODOT_GDEXTENSION_DIR}/extension_api.json")
    if (NOT "${GODOT_CUSTOM_API_FILE}" STREQUAL "")  # User-defined override.
        set(GODOT_GDEXTENSION_API_FILE "${GODOT_CUSTOM_API_FILE}")
    endif()

    if ("${GODOT_PRECISION}" STREQUAL "double")
        add_definitions(-DREAL_T_IS_DOUBLE)
    endif()

    set( GODOT_COMPILE_FLAGS )

    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
        # using Visual Studio C++
        set(GODOT_COMPILE_FLAGS "/utf-8") # /GF /MP

        if(CMAKE_BUILD_TYPE MATCHES Debug)
            set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} /MDd") # /Od /RTC1 /Zi
        else()
            set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} /MD /O2") # /Oy /GL /Gy
        endif(CMAKE_BUILD_TYPE MATCHES Debug)

        add_definitions(-DNOMINMAX)
    else()  # GCC/Clang
        if(CMAKE_BUILD_TYPE MATCHES Debug)
            set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} -fno-omit-frame-pointer -O0 -g")
        else()
            set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} -O3")
        endif(CMAKE_BUILD_TYPE MATCHES Debug)
    endif()

    # Disable exception handling. Godot doesn't use exceptions anywhere, and this
    # saves around 20% of binary size and very significant build time (GH-80513).
    if (GODOT_DISABLE_EXCEPTIONS)
        if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
            set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} -D_HAS_EXCEPTIONS=0")
        else()
            set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} -fno-exceptions")
        endif()
    else()
        if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
            set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} /EHsc")
        endif()
    endif()

    # Generate source from the bindings file
    find_package(Python3 3.4 REQUIRED) # pathlib should be present
    if(GODOT_GENERATE_TEMPLATE_GET_NODE)
        set(GENERATE_BINDING_PARAMETERS "True")
    else()
        set(GENERATE_BINDING_PARAMETERS "False")
    endif()

    execute_process(COMMAND "${Python3_EXECUTABLE}" "-c" "import binding_generator; binding_generator.print_file_list(\"${GODOT_GDEXTENSION_API_FILE}\", \"${CMAKE_CURRENT_BINARY_DIR}\", headers=True, sources=True)"
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            OUTPUT_VARIABLE GENERATED_FILES_LIST
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    add_custom_command(OUTPUT ${GENERATED_FILES_LIST}
            COMMAND "${Python3_EXECUTABLE}" "-c" "import binding_generator; binding_generator.generate_bindings(\"${GODOT_GDEXTENSION_API_FILE}\", \"${GENERATE_BINDING_PARAMETERS}\", \"${BITS}\", \"${GODOT_PRECISION}\", \"${CMAKE_CURRENT_BINARY_DIR}\")"
            VERBATIM
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            MAIN_DEPENDENCY ${GODOT_GDEXTENSION_API_FILE}
            DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/binding_generator.py
            COMMENT "Generating bindings"
    )

    # Get Sources
    # As this cmake file was added using 'include(godotcpp)' from the root CMakeLists.txt,
    # the ${CMAKE_CURRENT_SOURCE_DIR} is still the root dir.
    file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.c**)
    file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS include/*.h**)

    # Define our godot-cpp library
    add_library(${PROJECT_NAME} STATIC
            ${SOURCES}
            ${HEADERS}
            ${GENERATED_FILES_LIST}
    )
    add_library(godot::cpp ALIAS ${PROJECT_NAME})

    include(${PROJECT_SOURCE_DIR}/cmake/common_compiler_flags.cmake)

    target_compile_features(${PROJECT_NAME}
            PRIVATE
            cxx_std_17
    )

    if(GODOT_USE_HOT_RELOAD)
        target_compile_definitions(${PROJECT_NAME} PUBLIC HOT_RELOAD_ENABLED)
        target_compile_options(${PROJECT_NAME} PUBLIC $<${compiler_is_gnu}:-fno-gnu-unique>)
    endif()

    target_compile_definitions(${PROJECT_NAME} PUBLIC
            $<$<CONFIG:Debug>:
            DEBUG_ENABLED
            DEBUG_METHODS_ENABLED
            >
            $<${compiler_is_msvc}:
            TYPED_METHOD_BIND
            >
    )

    target_link_options(${PROJECT_NAME} PRIVATE
            $<$<NOT:${compiler_is_msvc}>:
            -static-libgcc
            -static-libstdc++
            -Wl,-R,'$$ORIGIN'
            >
    )

    # Optionally mark headers as SYSTEM
    set(GODOT_SYSTEM_HEADERS_ATTRIBUTE "")
    if (GODOT_SYSTEM_HEADERS)
        set(GODOT_SYSTEM_HEADERS_ATTRIBUTE SYSTEM)
    endif ()

    target_include_directories(${PROJECT_NAME} ${GODOT_SYSTEM_HEADERS_ATTRIBUTE} PUBLIC
            include
            ${CMAKE_CURRENT_BINARY_DIR}/gen/include
            ${GODOT_GDEXTENSION_DIR}
    )

    # Add the compile flags
    set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY COMPILE_FLAGS ${GODOT_COMPILE_FLAGS})

    # Create the correct name (godot.os.build_type.system_bits)
    string(TOLOWER "${CMAKE_SYSTEM_NAME}" SYSTEM_NAME)
    string(TOLOWER "${CMAKE_BUILD_TYPE}" BUILD_TYPE)

    if(ANDROID)
        # Added the android abi after system name
        set(SYSTEM_NAME ${SYSTEM_NAME}.${ANDROID_ABI})

        # Android does not have the bits at the end if you look at the main godot repo build
        set(OUTPUT_NAME "godot-cpp.${SYSTEM_NAME}.${BUILD_TYPE}")
    else()
        set(OUTPUT_NAME "godot-cpp.${SYSTEM_NAME}.${BUILD_TYPE}.${BITS}")
    endif()

    set_target_properties(${PROJECT_NAME}
            PROPERTIES
            CXX_EXTENSIONS OFF
            POSITION_INDEPENDENT_CODE ON
            CXX_VISIBILITY_PRESET ${GODOT_SYMBOL_VISIBILITY}
            ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin"
            LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin"
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin"
            OUTPUT_NAME "${OUTPUT_NAME}"
    )

endfunction()
