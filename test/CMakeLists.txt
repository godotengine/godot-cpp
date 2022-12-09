project(godot-cpp-test)
cmake_minimum_required(VERSION 3.12)

set(GODOT_GDEXTENSION_DIR ../gdextension/ CACHE STRING "Path to GDExtension interface header directory")
set(CPP_BINDINGS_PATH ../ CACHE STRING "Path to C++ bindings")

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	set(TARGET_PATH x11)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	set(TARGET_PATH win64)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
	set(TARGET_PATH macos)
else()
	message(FATAL_ERROR "Not implemented support for ${CMAKE_SYSTEM_NAME}")
endif()

set(GODOT_COMPILE_FLAGS )

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	# using Visual Studio C++
	set(GODOT_COMPILE_FLAGS "/WX")
	set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} /DTYPED_METHOD_BIND")

	# Disable conversion warning, truncation, unreferenced var, signed mismatch
	set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} /wd4244 /wd4305 /wd4101 /wd4018 /wd4267")

	add_definitions(-DNOMINMAX)
else()
	set(GODOT_COMPILE_FLAGS "-Wwrite-strings")
	set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} -Wchar-subscripts -Wcomment -Wdisabled-optimization")
	set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} -Wformat -Wformat=2 -Wformat-security -Wformat-y2k")
	set(GODOT_COMPILE_FLAGS "${GODOT_COMPILE_FLAGS} -Wimport -Winit-self -Winline -Winvalid-pch -Werror")
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

# Get Sources
file(GLOB_RECURSE SOURCES src/*.c**)
file(GLOB_RECURSE HEADERS include/*.h**)

# Define our godot-cpp library
add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})

target_compile_features(${PROJECT_NAME}
	PRIVATE
		cxx_std_17
)

target_include_directories(${PROJECT_NAME} SYSTEM
	PRIVATE
		${CPP_BINDINGS_PATH}/include
		${CPP_BINDINGS_PATH}/gen/include
		${GODOT_GDEXTENSION_DIR}
)

# Create the correct name (godot-cpp.os.build_type.system_bits)
# Synchronized with godot-cpp's CMakeLists.txt

set(BITS 32)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(BITS 64)
endif(CMAKE_SIZEOF_VOID_P EQUAL 8)

set(SYSTEM_NAME "$<LOWER_CASE:$<PLATFORM_ID>>")
set(BUILD_TYPE "$<LOWER_CASE:$<CONFIG>>")

if(ANDROID)
	# Added the android abi after system name
	set(SYSTEM_NAME ${SYSTEM_NAME}.${ANDROID_ABI})
endif()

if(CMAKE_VERSION VERSION_GREATER "3.13")
	target_link_directories(${PROJECT_NAME}
		PRIVATE
		${CPP_BINDINGS_PATH}/bin/
	)

	target_link_libraries(${PROJECT_NAME}
		godot-cpp.${SYSTEM_NAME}.${BUILD_TYPE}$<$<NOT:$<PLATFORM_ID:Android>>:.${BITS}>
	)
else()
	target_link_libraries(${PROJECT_NAME}
			${CPP_BINDINGS_PATH}/bin/libgodot-cpp.${SYSTEM_NAME}.${BUILD_TYPE}$<$<NOT:$<PLATFORM_ID:Android>>:.${BITS}>.a
	)
endif()

# Add the compile flags
set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY COMPILE_FLAGS ${GODOT_COMPILE_FLAGS})

set(BUILD_PATH ${CMAKE_SOURCE_DIR}/bin/${TARGET_PATH})

set_target_properties(${PROJECT_NAME}
	PROPERTIES
		CXX_EXTENSIONS OFF
		POSITION_INDEPENDENT_CODE ON
		ARCHIVE_OUTPUT_DIRECTORY "${BUILD_PATH}"
		LIBRARY_OUTPUT_DIRECTORY "${BUILD_PATH}"
		RUNTIME_OUTPUT_DIRECTORY "${BUILD_PATH}"
		OUTPUT_NAME "gdexample"
)
