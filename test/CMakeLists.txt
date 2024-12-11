#[=======================================================================[.rst:
Integration Testing
-------------------

The Test target used to validate changes in the GitHub CI.

]=======================================================================]

message( STATUS "Testing Integration targets are enabled.")

foreach( TARGET_ALIAS template_debug template_release editor )
    set( TARGET_NAME "godot-cpp.test.${TARGET_ALIAS}" )
    set( LINK_TARGET "godot-cpp::${TARGET_ALIAS}" )

    ### Get useful properties of the library
    get_target_property( GODOT_PLATFORM ${LINK_TARGET} GODOT_PLATFORM   )
    get_target_property( GODOT_TARGET   ${LINK_TARGET} GODOT_TARGET     )
    get_target_property( GODOT_ARCH     ${LINK_TARGET} GODOT_ARCH       )
    get_target_property( OSX_ARCH       ${LINK_TARGET} OSX_ARCHITECTURES )

    set( DEV_TAG "$<$<BOOL:${GODOT_DEV_BUILD}>:.dev>" )

    if( CMAKE_SYSTEM_NAME STREQUAL Darwin )
        set( OUTPUT_DIR "${OUTPUT_DIR}/libgdexample.macos.${TEST_TARGET}.framework")
        set( OUTPUT_NAME "gdexample.macos.${TEST_TARGET}${DEV_TAG}" )
    else()
        set( OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/project/bin/" )
        set( OUTPUT_NAME "gdexample.${GODOT_PLATFORM}.${GODOT_TARGET}${DEV_TAG}.${GODOT_ARCH}" )
    endif()

    add_library( ${TARGET_NAME} SHARED EXCLUDE_FROM_ALL )

    target_sources( ${TARGET_NAME}
            PRIVATE
            src/example.cpp
            src/example.h
            src/register_types.cpp
            src/register_types.h
            src/tests.h
    )

    target_link_libraries( ${TARGET_NAME} PRIVATE ${LINK_TARGET} )

    set_target_properties( ${TARGET_NAME}
            PROPERTIES
            CXX_STANDARD 17
            CXX_EXTENSIONS OFF
            CXX_VISIBILITY_PRESET ${GODOT_SYMBOL_VISIBILITY}

            # This flag adds the runtime path at build time
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
            OUTPUT_NAME "gdexample.${GODOT_PLATFORM}.${GODOT_TARGET}${DEV_TAG}.${GODOT_ARCH}"

            #macos options, ignored on other platforms
            OSX_ARCHITECTURES "${OSX_ARCH}"

            # enable RPATH on MACOS, with the BUILD_RPATH_USE_ORIGIN
            # this should allow loading libraries from relative paths on macos.
            MACOSX_RPATH ON

            # Some IDE's respect this property to logically group targets
            FOLDER "godot-cpp"
    )

    # Only blank the suffix on osx to match SCons
    if( CMAKE_SYSTEM_NAME STREQUAL Darwin )
        set_target_properties( ${TARGET_NAME} PROPERTIES SUFFIX "" )
    endif ()

endforeach()
