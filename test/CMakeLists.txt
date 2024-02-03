# Configuration can be used as a template for custom project, read comments
cmake_minimum_required(VERSION 3.6)
project(gdexample LANGUAGES CXX)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo;MinSizeRel")
set(GODOT_CPP_PATH ../)	# path to godot-cpp repository

add_subdirectory(
	${GODOT_CPP_PATH}
	${CMAKE_CURRENT_BINARY_DIR}/godot-cpp 	# needed because godot-cpp is top directory
)

# Get Sources
file(GLOB_RECURSE SOURCES src/*.c**)
file(GLOB_RECURSE HEADERS src/*.h**)

# Define our godot-cpp library
if(${PLATFORM} STREQUAL "WEB")
	# wasm libraries loaded with dlopen() are created like this in cmake
	add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
	set_target_properties(${PROJECT_NAME}
		PROPERTIES
			SUFFIX ".wasm"
	)
elseif(${PLATFORM} STREQUAL "MACOS")
	# TODO: create framework with cmake FRAMEWORK property
	# or with template file
	message(WARNING "Mac/IOS framework configuration is not tested and may not work.")

	add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
	set_target_properties(${PROJECT_NAME} PROPERTIES
		FRAMEWORK TRUE
		MACOSX_FRAMEWORK_IDENTIFIER com.godotengine.${PROJECT_NAME}
		MACOSX_FRAMEWORK_INFO_PLIST Info.plist
	)
else()
	add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC godot-cpp)

get_directory_property(GODOT_CC_FLAGS DIRECTORY ${GODOT_CPP_PATH} DEFINITION GODOT_CC_FLAGS)
get_directory_property(GODOT_CXX_FLAGS DIRECTORY ${GODOT_CPP_PATH} DEFINITION GODOT_CXX_FLAGS)
target_compile_options(${PROJECT_NAME} PRIVATE
	${GODOT_CC_FLAGS}
	${GODOT_CXX_FLAGS}
)

get_directory_property(GODOT_LINK_FLAGS DIRECTORY ${GODOT_CPP_PATH} DEFINITION GODOT_LINK_FLAGS)
target_link_options(${PROJECT_NAME} PRIVATE ${GODOT_LINK_FLAGS})


get_directory_property(LIBRARY_SUFFIX DIRECTORY ${GODOT_CPP_PATH} DEFINITION LIBRARY_SUFFIX)
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

		OUTPUT_NAME "${PROJECT_NAME}${LIBRARY_SUFFIX}"
)
if(${GODOT_CPP_WARNING_AS_ERROR})
	set_warning_as_error(${PROJECT_NAME})
endif()

