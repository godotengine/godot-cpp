# cmake arguments
# CMAKE_BUILD_TYPE:			Compilation target for single-configuration generators (Debug or Release - defaults to Debug)
#
# godot-cpp cmake arguments
# GODOT_GDEXTENSION_DIR:	Path to the directory containing GDExtension interface header and API JSON file
# GODOT_CPP_SYSTEM_HEADERS	Mark the header files as SYSTEM. This may be useful to supress warnings in projects including this one.
# GODOT_CUSTOM_API_FILE:	Path to a custom GDExtension API JSON file (takes precedence over `gdextension_dir`)
# FLOAT_PRECISION:			Floating-point precision level ("single", "double")
#
# Android cmake arguments
# CMAKE_TOOLCHAIN_FILE:		The path to the android cmake toolchain ($ANDROID_NDK/build/cmake/android.toolchain.cmake)
# ANDROID_NDK:				The path to the android ndk root folder
# ANDROID_TOOLCHAIN_NAME:	The android toolchain (arm-linux-androideabi-4.9 or aarch64-linux-android-4.9 or x86-4.9 or x86_64-4.9)
# ANDROID_PLATFORM:			The android platform version (android-23)
# More info here: https://godot.readthedocs.io/en/latest/development/compiling/compiling_for_android.html
#
# Examples
#
# Builds a release version with clang
# CC=/usr/bin/clang CXX=/usr/bin/clang++ cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" .
# cmake --build .
#
# Builds a release version with MSVC
# cmake -G"Visual Studio 16 2019" .
# cmake --build . --config Release
#
# Builds an android armeabi-v7a debug version:
# cmake -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake -DANDROID_NDK=$ANDROID_NDK \
#		-DANDROID_TOOLCHAIN_NAME=arm-linux-androideabi-4.9 -DANDROID_PLATFORM=android-23 -DCMAKE_BUILD_TYPE=Debug .
# cmake --build .
#
# Protip
# Generate the buildfiles in a sub directory to not clutter the root directory with build files:
# mkdir build && cd build && cmake -G "Unix Makefiles" .. && cmake --build .
#
# Todo
# Test build for Windows, Mac and mingw.

project(godot-cpp LANGUAGES CXX)
cmake_minimum_required(VERSION 3.12)

option(GENERATE_TEMPLATE_GET_NODE "Generate a template version of the Node class's get_node." ON)
option(GODOT_CPP_SYSTEM_HEADERS "Expose headers as SYSTEM." OFF)


if(NOT DEFINED BITS)
	set(BITS 32)
	if(CMAKE_SIZEOF_VOID_P EQUAL 8)
		set(BITS 64)
	endif(CMAKE_SIZEOF_VOID_P EQUAL 8)
endif()

# Input from user for GDExtension interface header and the API JSON file
set(GODOT_GDEXTENSION_DIR "gdextension" CACHE STRING "")
set(GODOT_CUSTOM_API_FILE "" CACHE STRING "")
set(FLOAT_PRECISION "single" CACHE STRING "")
if ("${FLOAT_PRECISION}" STREQUAL "double")
	add_definitions(-DREAL_T_IS_DOUBLE)
endif()

set(GODOT_GDEXTENSION_API_FILE "${GODOT_GDEXTENSION_DIR}/extension_api.json")
if (NOT "${GODOT_CUSTOM_API_FILE}" STREQUAL "")  # User-defined override.
	set(GODOT_GDEXTENSION_API_FILE "${GODOT_CUSTOM_API_FILE}")
endif()

set(GODOT_COMPILE_FLAGS )
set(GODOT_LINKER_FLAGS )

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	# using Visual Studio C++
	set(GODOT_COMPILE_FLAGS "/WX")

	# Disable conversion warning, truncation, unreferenced var, signed mismatch, different type
	set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} /wd4244 /wd4305 /wd4101 /wd4018 /wd4267 /wd4099")

	add_definitions(-DNOMINMAX)
else()  # GCC/Clang
	set(GODOT_LINKER_FLAGS "-static-libgcc -static-libstdc++ -Wl,-R,'$$ORIGIN'")

	if(NOT CMAKE_SYSTEM_NAME MATCHES "Windows")
		set(GODOT_COMPILE_FLAGS "-fPIC")
	endif()
	set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} -Wwrite-strings")
	set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} -Wchar-subscripts -Wcomment -Wdisabled-optimization")
	set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} -Wformat -Wformat=2 -Wformat-security -Wformat-y2k")
	set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} -Wimport -Winit-self -Winline -Winvalid-pch")
	set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} -Wmissing-braces -Wmissing-format-attribute")
	set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} -Wmissing-include-dirs -Wmissing-noreturn -Wpacked -Wpointer-arith")
	set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} -Wredundant-decls -Wreturn-type -Wsequence-point")
	set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} -Wswitch -Wswitch-enum -Wtrigraphs")
	set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} -Wuninitialized -Wunknown-pragmas -Wunreachable-code -Wunused-label")
	set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} -Wunused-value -Wvariadic-macros -Wvolatile-register-var -Wno-error=attributes")

	if(NOT CMAKE_SYSTEM_NAME STREQUAL "Android")
		set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} -Wno-ignored-attributes")
	endif()
endif()

# Generate source from the bindings file
find_package(Python3 3.4 REQUIRED) # pathlib should be present
if(GENERATE_TEMPLATE_GET_NODE)
	set(GENERATE_BINDING_PARAMETERS "True")
else()
	set(GENERATE_BINDING_PARAMETERS "False")
endif()

execute_process(COMMAND "${Python3_EXECUTABLE}" "-c" "import binding_generator; binding_generator.print_file_list(\"${GODOT_GDEXTENSION_API_FILE}\", \"${CMAKE_CURRENT_BINARY_DIR}\", headers=True, sources=True)"
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	OUTPUT_VARIABLE GENERATED_FILES_LIST
)

add_custom_command(OUTPUT ${GENERATED_FILES_LIST}
		COMMAND "${Python3_EXECUTABLE}" "-c" "import binding_generator; binding_generator.generate_bindings(\"${GODOT_GDEXTENSION_API_FILE}\", \"${GENERATE_BINDING_PARAMETERS}\", \"${BITS}\", \"${FLOAT_PRECISION}\", \"${CMAKE_CURRENT_BINARY_DIR}\")"
		VERBATIM
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		MAIN_DEPENDENCY ${GODOT_GDEXTENSION_API_FILE}
		DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/binding_generator.py
		COMMENT "Generating bindings"
)

# Get Sources
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.c**)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS include/*.h**)

# Define our godot-cpp library
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

target_compile_definitions(${PROJECT_NAME} PUBLIC
	$<$<CONFIG:Debug>:DEBUG_ENABLED>
	$<$<CONFIG:Debug>:DEBUG_METHODS_ENABLED>
)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	target_compile_definitions(${PROJECT_NAME} PUBLIC TYPED_METHOD_BIND)
endif()

# Optionally mark headers as SYSTEM
set(GODOT_CPP_SYSTEM_HEADERS_ATTRIBUTE "")
if (GODOT_CPP_SYSTEM_HEADERS)
	set(GODOT_CPP_SYSTEM_HEADERS_ATTRIBUTE SYSTEM)
endif ()

target_include_directories(${PROJECT_NAME} ${GODOT_CPP_SYSTEM_HEADERS_ATTRIBUTE} PUBLIC
	include
	${CMAKE_CURRENT_BINARY_DIR}/gen/include
)

unset( GODOT_CPP_SYSTEM_HEADERS_ATTRIBUTE )

# Put godot headers as SYSTEM PUBLIC to exclude warnings from irrelevant headers
target_include_directories(${PROJECT_NAME}
	SYSTEM PUBLIC
	${GODOT_GDEXTENSION_DIR}
)

# Add the compile flags
set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY COMPILE_FLAGS ${GODOT_COMPILE_FLAGS})
set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY LINK_FLAGS ${GODOT_LINKER_FLAGS})

# Create the correct name (godot-cpp.os.build_type.system_bits)
set(SYSTEM_NAME "$<LOWER_CASE:$<PLATFORM_ID>>")
set(BUILD_TYPE "$<LOWER_CASE:$<CONFIG>>")

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
		ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin"
		LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin"
		OUTPUT_NAME "${OUTPUT_NAME}"
)
