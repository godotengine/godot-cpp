#[=======================================================================[.rst:
Integration Testing
-------------------

The Test target used to validate changes in the GitHub CI.
]=======================================================================]

message(STATUS "Testing Integration targets are enabled.")

set(TARGET_NAME "godot-cpp-test")

add_library(${TARGET_NAME} SHARED EXCLUDE_FROM_ALL)

target_sources(
    ${TARGET_NAME}
    PRIVATE src/example.cpp src/example.h src/register_types.cpp src/register_types.h src/tests.h
)

# conditionally add doc data to compile output
if(GODOTCPP_TARGET MATCHES "editor|template_debug")
    file(GLOB_RECURSE DOC_XML LIST_DIRECTORIES NO CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/doc_classes/*.xml")
    target_doc_sources( ${TARGET_NAME} "${DOC_XML}" )
endif()

set(OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/project/bin/")

# Link to godot-cpp target
target_link_libraries(${TARGET_NAME} PRIVATE godot-cpp)

### Get useful properties from godot-cpp target
get_target_property(GODOTCPP_SUFFIX godot-cpp GODOTCPP_SUFFIX)
get_target_property(GODOTCPP_TARGET godot-cpp GODOTCPP_TARGET)

# gersemi: off
set_target_properties(
    ${TARGET_NAME}
    PROPERTIES
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        CXX_VISIBILITY_PRESET ${GODOTCPP_SYMBOL_VISIBILITY}

        POSITION_INDEPENDENT_CODE ON
        BUILD_RPATH_USE_ORIGIN ON

        # Try to ensure only static libraries are selected to be linked to.
        LINK_SEARCH_START_STATIC ON
        LINK_SEARCH_END_STATIC ON

        # NOTE: Wrapping the output variables inside a generator expression
        # prevents msvc generator from adding addition Config Directories
        LIBRARY_OUTPUT_DIRECTORY "$<1:${OUTPUT_DIR}>"
        RUNTIME_OUTPUT_DIRECTORY "$<1:${OUTPUT_DIR}>"
        PDB_OUTPUT_DIRECTORY     "$<1:${OUTPUT_DIR}>" #MSVC Only, ignored on other platforms

        PREFIX "lib"
        OUTPUT_NAME "gdexample${GODOTCPP_SUFFIX}"
        # TODO rename the file for both CMake and SCons

        # Some IDE's respect this property to logically group targets
        FOLDER "godot-cpp"
)
# gersemi: on

if(CMAKE_SYSTEM_NAME STREQUAL "Windows" AND MINGW)
    # Make the GDExtension DLL self-contained (no external MinGW runtime DLLs)
    target_link_options(${TARGET_NAME} PRIVATE "$<IF:$<BOOL:${MINGW}>,-static-libgcc;-static-libstdc++,>")

    # Also ensure no undefined symbols
    target_link_options(${TARGET_NAME} PRIVATE -Wl,--no-undefined)
endif()

if(CMAKE_SYSTEM_NAME STREQUAL Darwin)
    set_target_properties(
        ${TARGET_NAME}
        PROPERTIES
            OUTPUT_NAME "libgdexample.macos.${GODOTCPP_TARGET}"
            FRAMEWORK TRUE
            FRAMEWORK_VERSION A
            MACOSX_FRAMEWORK_IDENTIFIER
                "com.godot.gdexample" # can be anything, doesn't matter much
            MACOSX_FRAMEWORK_BUNDLE_VERSION 1.0
            MACOSX_FRAMEWORK_SHORT_VERSION_STRING 1.0
            # These help with rpath and universal builds
            MACOSX_RPATH TRUE
            INSTALL_NAME_DIR "@rpath"
            BUILD_WITH_INSTALL_NAME_DIR TRUE
    )
endif()
