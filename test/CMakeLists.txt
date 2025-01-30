#[=======================================================================[.rst:
Integration Testing
-------------------

The Test target used to validate changes in the GitHub CI.
]=======================================================================]

message( STATUS "Testing Integration targets are enabled.")

# Generate Doc Data
file( GLOB_RECURSE DOC_XML
    LIST_DIRECTORIES NO
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/doc_classes/*.xml" )

set( DOC_DATA_SOURCE "${CMAKE_CURRENT_BINARY_DIR}/src/gen/doc_data.gen.cpp" )
generate_doc_source( "${DOC_DATA_SOURCE}" "${DOC_XML}" )

foreach( TARGET_ALIAS template_debug template_release editor )
    set( TARGET_NAME "godot-cpp.test.${TARGET_ALIAS}" )
    set( LINK_TARGET "godot-cpp::${TARGET_ALIAS}" )

    ### Get useful properties of the library
    get_target_property( GODOT_SUFFIX   ${LINK_TARGET} GODOT_SUFFIX      )
    get_target_property( OSX_ARCH       ${LINK_TARGET} OSX_ARCHITECTURES )

    set( OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/project/bin/" )

    add_library( ${TARGET_NAME} SHARED EXCLUDE_FROM_ALL )

    target_sources( ${TARGET_NAME}
            PRIVATE
            src/example.cpp
            src/example.h
            src/register_types.cpp
            src/register_types.h
            src/tests.h
    )

    # conditionally add doc data to compile output
    if( TARGET_ALIAS MATCHES "editor|template_debug" )
        target_sources( ${TARGET_NAME} PRIVATE "${DOC_DATA_SOURCE}" )
    endif(   )

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
            OUTPUT_NAME "gdexample${GODOT_SUFFIX}"

            #macos options, ignored on other platforms
            OSX_ARCHITECTURES "${OSX_ARCH}"

            # enable RPATH on MACOS, with the BUILD_RPATH_USE_ORIGIN
            # this should allow loading libraries from relative paths on macos.
            MACOSX_RPATH ON

            # Some IDE's respect this property to logically group targets
            FOLDER "godot-cpp"
    )

    target_compile_options(  ${TARGET_NAME}
            PRIVATE
            # The test project uses utf-8 characters in its source files:
            # example.h:282.283, and example.cpp:774,8775,778
            # which require interpretation of source files as utf-8 by MSVC
            $<${IS_MSVC}:/utf-8>
    )

    # Only blank the suffix on osx to match SCons
    if( CMAKE_SYSTEM_NAME STREQUAL Darwin )
        set_target_properties( ${TARGET_NAME}
                PROPERTIES
                SUFFIX ""
                OUTPUT_DIR "${OUTPUT_DIR}/libgdexample.macos.${TARGET_ALIAS}.framework"
        )
    endif ()

endforeach()
