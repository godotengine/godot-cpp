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

    # Disable exception handling. Godot doesn't use exceptions anywhere, and this
    # saves around 20% of binary size and very significant build time (GH-80513).
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
    ### Configure variables
    # CXX_VISIBILITY_PRESET supported values are: default, hidden, protected, and internal
    # which is inline with the gcc -fvisibility=
    # https://gcc.gnu.org/onlinedocs/gcc/Code-Gen-Options.html
    # To match the scons options we need to change the text to match the -fvisibility flag
    # it is probably worth another PR which changes both to use the flag options
    if( ${GODOT_SYMBOL_VISIBILITY} STREQUAL "auto" OR ${GODOT_SYMBOL_VISIBILITY} STREQUAL "visible" )
        set( GODOT_SYMBOL_VISIBILITY "default" )
    endif ()

    ### Generate Bindings
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

    # Generate source from the bindings file
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

    ### Define our godot-cpp library
    add_library(${PROJECT_NAME} STATIC )
    add_library(godot::cpp ALIAS ${PROJECT_NAME})

    # Get Sources
    include( cmake/sources.cmake )
    target_sources( ${PROJECT_NAME}
            PRIVATE
            ${GODOTCPP_HEADERS}
            ${GODOTCPP_SOURCES}
            ${GENERATED_FILES_LIST}
    )

    #This exposes the include directory to consumers
    target_include_directories( ${PROJECT_NAME}
            INTERFACE
            ${PROJECT_SOURCE_DIR}/include/godot_cpp
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

    include(${PROJECT_SOURCE_DIR}/cmake/common_compiler_flags.cmake)

    ### Create the correct name (godot.os.build_type.system_bits)
    set( SYSTEM_NAME "$<LOWER_CASE:${CMAKE_SYSTEM_NAME}>" )
    set( BUILD_TYPE "$<LOWER_CASE:$<CONFIG>>" )

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
