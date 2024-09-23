cmake_minimum_required(VERSION 3.13)
project(godot-cpp-test LANGUAGES CXX)

if( NOT CMAKE_BUILD_TYPE )
    set(CMAKE_BUILD_TYPE Release)
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	set(TARGET_PATH x11)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	set(TARGET_PATH win64)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
	set(TARGET_PATH macos)
else()
	message(FATAL_ERROR "Not implemented support for ${CMAKE_SYSTEM_NAME}")
endif()

set( IS_CLANG "$<OR:$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:Clang>>" )
set( IS_GNU "$<CXX_COMPILER_ID:GNU>" )
set( IS_MSVC "$<CXX_COMPILER_ID:MSVC>" )


# Define our godot-cpp library
add_library(${PROJECT_NAME} SHARED EXCLUDE_FROM_ALL )

target_sources(${PROJECT_NAME}
        PRIVATE
        src/example.cpp
        src/example.h
        src/register_types.cpp
        src/register_types.h
        src/tests.h
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        godot::cpp )

target_compile_options(${PROJECT_NAME}
        PRIVATE
        $<$<OR:${IS_CLANG},${IS_GNU}>:
            -fPIC
            -Wwrite-strings
        >
)

target_link_options( ${PROJECT_NAME}
        PRIVATE
        $<$<OR:${IS_CLANG},${IS_GNU}>:
            -static-libgcc
            -static-libstdc++
        >
        $<$<PLATFORM_ID:Linux>:
            $<${IS_GNU}:
                -Wl,-R,'$$ORIGIN'
            >
        >
)

set_target_properties( ${PROJECT_NAME}
        PROPERTIES
        OUTPUT_NAME "gdexample"
        POSITION_INDEPENDENT_CODE ON
        BUILD_RPATH_USE_ORIGIN ON
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${TARGET_PATH}
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${TARGET_PATH}
)
