# Main cmake arguments
#
# CMAKE_BUILD_TYPE			Compilation target (Debug, Release, RelWithDebInfo, MinSizeRel)
#
# CMAKE_CONFIGURATION_TYPES 		Set to "Debug;Release;RelWithDebInfo;MinSizeRel"
#					if not all needed configurations are created in multi-config generator
#					(Setting it in script causes crash on Ninja Multi-Config)
#
# TARGET				Godot build target (EDITOR, TEMPLATE_DEBUG, TEMPLATE_RELEASE)
#
# PLATFORM:	Platform type (LINUX, MACOS, WINDOWS, ANDROID, IOS, WEB)
# Auto-detected by default depending on current OS or chosen toolchain
#
# other global and chosen platform-specific options:
#
# cmake -LH <build_dir>
#
# Note: use `-B <build_dir>` option to build in separate directories
# for different configurations
#
# cmake -B build && cmake --build build
#
# Examples
#
# Builds default configuration:
# cmake . -Bbuild
# cmake --build build
#
# Builds template_release version
#
# cmake -DTARGET=TEMPLATE_RELEASE -Bbuild
# cmake --build build
#
# Creates multi-config setup and builds Release version (example for Linux)
#
# cmake -G "Ninja Multi-Config" -Bbuild
# cmake --build build --config Release
#
# Builds web version, using Emscripten toolchain
#
# cmake --toolchain /usr/lib/emscripten/cmake/Modules/Platform/Emscripten.cmake -Bbuild
# cmake --build build
#
#
# Builds an android armeabi-v7a debug version:
# cmake --toolchain $ANDROID_NDK/build/cmake/android.toolchain.cmake \
# 	-DANDROID_TOOLCHAIN_NAME=arm-linux-androideabi-4.9 -DANDROID_TOOLCHAIN=clang -DANDROID_PLATFORM=21 -Bbuild
# cmake --build build
#
#
# TODO:
# Test builds for MacOS/IOS

cmake_minimum_required(VERSION 3.12)
project(godot-cpp LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

# Handles all global and platform-specific variables
include(godotcpp)

# Generate source from the bindings file
find_package(Python3 3.4 REQUIRED) # pathlib should be present

execute_process(COMMAND "${Python3_EXECUTABLE}" "-c" "import binding_generator; binding_generator.print_file_list(\"${GDEXTENSION_API_FILE}\", \"${CMAKE_CURRENT_BINARY_DIR}\", headers=True, sources=True)"
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	OUTPUT_VARIABLE GENERATED_FILES_LIST
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

string(TOLOWER ${FLOAT_PRECISION} FLOAT_PRECISION_ARG)
if(GENERATE_TEMPLATE_GET_NODE)
	set(GENERATE_BINDING_PARAMETERS "True")
else()
	set(GENERATE_BINDING_PARAMETERS "False")
endif()

add_custom_command(OUTPUT ${GENERATED_FILES_LIST}
		COMMAND "${Python3_EXECUTABLE}" "-c" "import binding_generator; binding_generator.generate_bindings(\"${GDEXTENSION_API_FILE}\", \"${GENERATE_BINDING_PARAMETERS}\", \"${BITS}\", \"${FLOAT_PRECISION_ARG}\", \"${CMAKE_CURRENT_BINARY_DIR}\")"
		VERBATIM
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		MAIN_DEPENDENCY ${GDEXTENSION_API_FILE}
		DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/binding_generator.py
		COMMENT "Generating bindings"
)

# Get Sources
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.c**)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS include/*.h**)

# Define our godot-cpp library
add_library(${PROJECT_NAME} ${GODOT_CPP_LIBRARY_TYPE}
		${SOURCES}
		${HEADERS}
		${GENERATED_FILES_LIST}
)
add_library(godot::cpp ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} ${GODOT_CPP_SYSTEM_HEADERS_ATTRIBUTE} PUBLIC
	include
	${CMAKE_CURRENT_BINARY_DIR}/gen/include
	${GDEXTENSION_DIR}
)

target_compile_features(${PROJECT_NAME} PUBLIC
	cxx_std_17
)

target_compile_options(${PROJECT_NAME} PRIVATE
	${GODOT_CC_FLAGS}
	${GODOT_CXX_FLAGS}
	${GODOT_COMPILE_WARNING_FLAGS}
)

target_link_options(${PROJECT_NAME} PRIVATE ${GODOT_LINK_FLAGS})

target_compile_definitions(${PROJECT_NAME} PUBLIC ${GODOT_DEFINITIONS})

set_target_properties(${PROJECT_NAME}
	PROPERTIES
		CXX_EXTENSIONS OFF
		POSITION_INDEPENDENT_CODE ON
		ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin"
		LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin"
		OUTPUT_NAME "${PROJECT_NAME}${LIBRARY_SUFFIX}"
)
if(${GODOT_CPP_WARNING_AS_ERROR})
	set_warning_as_error(${PROJECT_NAME})
endif()
