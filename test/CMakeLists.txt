# Testing Extension
# This is only linked to the template_release config.
# so it requires the template_release version of godot to run.

add_library( godot-cpp-test SHARED EXCLUDE_FROM_ALL )

target_sources( godot-cpp-test
        PRIVATE
        src/example.cpp
        src/example.h
        src/register_types.cpp
        src/register_types.h
        src/tests.h
)

set( TEST_TARGET "template_debug" CACHE STRING "Which godot-cpp::target to link against" )
set_property( CACHE TEST_TARGET PROPERTY STRINGS "template_debug;template_release;editor" )

target_link_libraries( godot-cpp-test
        PRIVATE
        godot-cpp::${TEST_TARGET} )

### Get useful properties of the library
get_target_property( GODOT_PLATFORM godot-cpp::${TEST_TARGET} GODOT_PLATFORM )
get_target_property( GODOT_TARGET godot-cpp::${TEST_TARGET} GODOT_TARGET )
get_target_property( GODOT_ARCH godot-cpp::${TEST_TARGET} GODOT_ARCH )

set( OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/project/bin/" )
set( DEV_TAG "$<$<BOOL:${GODOT_DEV_BUILD}>:.dev>" )

set_target_properties( godot-cpp-test
        PROPERTIES
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        CXX_VISIBILITY_PRESET ${GODOT_SYMBOL_VISIBILITY}

        POSITION_INDEPENDENT_CODE ON
        BUILD_RPATH_USE_ORIGIN ON
        LINK_SEARCH_START_STATIC ON
        LINK_SEARCH_END_STATIC ON

        # NOTE: Wrapping the output variables inside a generator expression
        # prevents msvc generator from adding addition Config Directories
        LIBRARY_OUTPUT_DIRECTORY "$<1:${OUTPUT_DIR}>"
        RUNTIME_OUTPUT_DIRECTORY "$<1:${OUTPUT_DIR}>"
        PDB_OUTPUT_DIRECTORY     "$<1:${OUTPUT_DIR}>" #MSVC Only, ignored on other platforms

        PREFIX "lib"
        OUTPUT_NAME "gdexample.${GODOT_PLATFORM}.${GODOT_TARGET}${DEV_TAG}.${GODOT_ARCH}"
)

if( CMAKE_SYSTEM_NAME STREQUAL Darwin )
    get_target_property( OSX_ARCH godot-cpp::${TEST_TARGET} OSX_ARCHITECTURES )

    set( OUTPUT_DIR "${OUTPUT_DIR}/libgdexample.macos.${TEST_TARGET}.framework")

    set_target_properties( godot-cpp-test
            PROPERTIES
            LIBRARY_OUTPUT_DIRECTORY "$<1:${OUTPUT_DIR}>"
            RUNTIME_OUTPUT_DIRECTORY "$<1:${OUTPUT_DIR}>"

            OUTPUT_NAME "gdexample.macos.${TEST_TARGET}${DEV_TAG}"
            SUFFIX ""

            #macos options
            OSX_ARCHITECTURES "${OSX_ARCH}"
    )
endif ()
