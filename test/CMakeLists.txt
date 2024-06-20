# Configuration can be used as a template for custom project, read comments
cmake_minimum_required(VERSION 3.13)
project(gdexample LANGUAGES CXX)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo;MinSizeRel")
set(GODOT_CPP_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../)	# path to godot-cpp repository

add_subdirectory(
	${GODOT_CPP_PATH}
	${CMAKE_CURRENT_BINARY_DIR}/godot-cpp 	# needed because godot-cpp is top directory
)

# Get Sources
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.c**)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS src/*.h**)

get_target_property(LIBRARY_SUFFIX godot-cpp LIBRARY_SUFFIX)

# Define our godot-cpp library
if(${GODOT_PLATFORM} STREQUAL "WEB")
	# wasm libraries loaded with dlopen() are created like this in cmake
	add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
	set_target_properties(${PROJECT_NAME}
		PROPERTIES
			SUFFIX ".wasm"
			OUTPUT_NAME "${PROJECT_NAME}${LIBRARY_SUFFIX}"
	)
elseif(${GODOT_PLATFORM} STREQUAL "MACOS")
	add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
	set(OUTPUT_NAME "lib${PROJECT_NAME}${LIBRARY_SUFFIX}")
	set_target_properties(${PROJECT_NAME} PROPERTIES
		FRAMEWORK TRUE
		MACOSX_FRAMEWORK_IDENTIFIER "org.godotengine.lib${PROJECT_NAME}"
		MACOSX_BUNDLE_BUNDLE_NAME "lib${PROJECT_NAME}${LIBRARY_SUFFIX}"
		MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0.0"
		MACOS_BUNDLE_BUNDLE_VERSION "1.0.0"

		OUTPUT_NAME "${OUTPUT_NAME}"
	)

	# Workaround of 'bin/***.framework/Resources' existing in godot-cpp repo by default'
	set(RESOURCES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/project/bin/${OUTPUT_NAME}.framework/Resources")
	if(IS_DIRECTORY ${RESOURCES_DIR} AND NOT IS_SYMLINK ${RESOURCES_DIR})
		message(STATUS "Removing '${RESOURCES_DIR}' to create symlink ...")
		file(REMOVE_RECURSE ${RESOURCES_DIR})
	endif()

# TODO: IOS configuration
#elseif(${GODOT_PLATFORM} STREQUAL "IOS")
else()
	add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
	set_target_properties(${PROJECT_NAME} PROPERTIES
		OUTPUT_NAME "${PROJECT_NAME}${LIBRARY_SUFFIX}"
)
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC godot-cpp)

get_target_property(GODOT_C_FLAGS godot-cpp GODOT_C_FLAGS)
get_target_property(GODOT_CXX_FLAGS godot-cpp GODOT_CXX_FLAGS)
target_compile_options(${PROJECT_NAME} PRIVATE
	${GODOT_C_FLAGS}
	${GODOT_CXX_FLAGS}
)

get_target_property(GODOT_LINK_FLAGS godot-cpp GODOT_LINK_FLAGS)
target_link_options(${PROJECT_NAME} PRIVATE ${GODOT_LINK_FLAGS})


get_target_property(LIBRARY_SUFFIX godot-cpp LIBRARY_SUFFIX)
set_target_properties(${PROJECT_NAME}
	PROPERTIES
		PREFIX "lib"
		LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/project/bin"
		LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/project/bin"
		LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/project/bin"
		LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_CURRENT_SOURCE_DIR}/project/bin"
		LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_CURRENT_SOURCE_DIR}/project/bin"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/project/bin"
		RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/project/bin"
		RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/project/bin"
		RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_CURRENT_SOURCE_DIR}/project/bin"
		RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_CURRENT_SOURCE_DIR}/project/bin"
)
if(${GODOT_CPP_WARNING_AS_ERROR})
	set_warning_as_error(${PROJECT_NAME})
endif()

