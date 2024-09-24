##########       Configuration for building godot-cpp only      ##########
########## See `tests/CMakeLists.txt` for example configuration ##########
#
# cmake arguments
#
# CMAKE_BUILD_TYPE				Compilation target (Debug, Release, RelWithDebInfo, MinSizeRel)
#
# CMAKE_CONFIGURATION_TYPES 	Set to "Debug;Release;RelWithDebInfo;MinSizeRel" in top project config or via cmdline (see `test/CMakeLists.txt`)
#
# godot-cpp cmake arguments
#
# GODOT_TARGET					Godot build target (EDITOR, TEMPLATE_DEBUG, TEMPLATE_RELEASE)
# GODOT_PLATFORM:				Platform type (LINUX, MACOS, WINDOWS, ANDROID, IOS, WEB). Auto-detected by default depending on current OS or chosen toolchain
# GODOT_GDEXTENSION_DIR:		Path to the directory containing GDExtension interface header and API JSON file
# GODOT_SYSTEM_HEADERS		Mark the header files as SYSTEM. This may be useful to suppress warnings in projects including this one.
# GODOT_WARNING_AS_ERROR	Treat any warnings as errors
# GODOT_USE_HOT_RELOAD			Build with hot reload support. Defaults to YES for Debug-builds and NO for Release-builds.
# GODOT_CUSTOM_API_FILE:		Path to a custom GDExtension API JSON file (takes precedence over `gdextension_dir`)
# GODOT_PRECISION:				Floating-point precision level ("single", "double")
#
# other global and platform-specific options:
#
# $ cmake -LH <build_dir>
#
# Note: use `-B <build_dir>` option to build in separate directories
# for different configurations
#
# $ cmake -B build && cmake --build build
#
# Examples
#
# Builds default debug configuration:
# $ cmake . -B build
# $ cmake --build build
#
#
# Builds template_release version with Release preset
# $ cmake -DCMAKE_BUILD_TYPE=Release -DGODOT_TARGET=TEMPLATE_RELEASE -B build
# $ cmake --build build
#
#
# Creates multi-config setup and builds Release version
#
# $ cmake -G "Ninja Multi-Config" -B build 		# For Linux/non-MSVC
#	OR
# $ cmake -G "Visual Studio 16 2019" -A x64 -B build 	# For Windows/MSVC
# $ cmake --build build --config Release
#
#
# Builds web version, using Emscripten toolchain
#
# $ cmake --toolchain /usr/lib/emscripten/cmake/Modules/Platform/Emscripten.cmake -B build
# $ cmake --build build
#
#
# Builds an android armeabi-v7a debug version:
# $ cmake --toolchain $ANDROID_NDK/build/cmake/android.toolchain.cmake \
# 	-DANDROID_TOOLCHAIN_NAME=arm-linux-androideabi-4.9 -DANDROID_TOOLCHAIN=clang -DANDROID_PLATFORM=21 -B build
# $ cmake --build build
#
#
# Builds MacOS version via Xcode
# $ cmake -G Xcode -B build
# $ cmake --build build
#
#
# Ensure that you avoid exposing godot-cpp symbols - this might lead to hard to debug errors if you ever load multiple
# plugins using different godot-cpp versions. Use visibility hidden whenever possible:
# set_target_properties(<all-my-plugin-related-targets> PROPERTIES CXX_VISIBILITY_PRESET hidden)
#

cmake_minimum_required(VERSION 3.13)
project(godot-cpp LANGUAGES CXX)

# Handles all global and platform-specific variables
include(${CMAKE_CURRENT_LIST_DIR}/cmake/godotcpp.cmake)

# Generate source from the bindings file
find_package(Python3 3.4 REQUIRED) # pathlib should be present

execute_process(COMMAND "${Python3_EXECUTABLE}" "-c" "import binding_generator; binding_generator.print_file_list(\"${GODOT_CUSTOM_API_FILE}\", \"${CMAKE_CURRENT_BINARY_DIR}\", headers=True, sources=True, profile_filepath=\"${GODOT_BUILD_PROFILE}\")"
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	OUTPUT_VARIABLE GENERATED_FILES_LIST
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

if(GODOT_GENERATE_TEMPLATE_GET_NODE)
	set(GENERATE_BINDING_PARAMETERS "True")
else()
	set(GENERATE_BINDING_PARAMETERS "False")
endif()

add_custom_command(OUTPUT ${GENERATED_FILES_LIST}
	COMMAND "${Python3_EXECUTABLE}" "-c" "import binding_generator; binding_generator.generate_bindings(\"${GODOT_CUSTOM_API_FILE}\", \"${GENERATE_BINDING_PARAMETERS}\", \"${GODOT_BITS}\", \"${GODOT_PRECISION}\", \"${CMAKE_CURRENT_BINARY_DIR}\")"
		VERBATIM
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		MAIN_DEPENDENCY ${GODOT_CUSTOM_API_FILE}
		DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/binding_generator.py
		COMMENT "Generating bindings"
)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.c**)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS include/*.h**)

add_library(${PROJECT_NAME}
		${SOURCES}
		${HEADERS}
		${GENERATED_FILES_LIST}
)
add_library(godot::cpp ALIAS ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME}
	PRIVATE
		cxx_std_17
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

target_compile_features(${PROJECT_NAME} PUBLIC
	cxx_std_17
)

target_compile_options(${PROJECT_NAME} PRIVATE
	${GODOT_C_FLAGS}
	${GODOT_CXX_FLAGS}
	${GODOT_COMPILE_WARNING_FLAGS}
)

target_link_options(${PROJECT_NAME} PRIVATE ${GODOT_LINK_FLAGS})

target_compile_definitions(${PROJECT_NAME} PUBLIC ${GODOT_DEFINITIONS})

set_target_properties(${PROJECT_NAME}
	PROPERTIES
		CXX_EXTENSIONS OFF
		POSITION_INDEPENDENT_CODE ON
		CXX_VISIBILITY_PRESET ${GODOT_SYMBOLS_VISIBILITY}
		GODOT_C_FLAGS "${GODOT_C_FLAGS}"
		GODOT_CXX_FLAGS "${GODOT_CXX_FLAGS}"
		GODOT_COMPILE_WARNING_FLAGS "${GODOT_COMPILE_WARNING_FLAGS}"
		GODOT_LINK_FLAGS "${GODOT_LINK_FLAGS}"
		LIBRARY_SUFFIX "${LIBRARY_SUFFIX}"
		ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin"
		LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin"
		OUTPUT_NAME "${PROJECT_NAME}${LIBRARY_SUFFIX}"
)
if(${GODOT_WARNING_AS_ERROR})
	set_warning_as_error(${PROJECT_NAME})
endif()
