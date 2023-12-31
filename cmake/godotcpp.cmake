# This file contains variables needed by all platforms

### Options

set(CMAKE_CONFIGURATION_TYPES "template_debug;editor;template_release")

if("${CMAKE_BUILD_TYPE}" STREQUAL "")
	set(CMAKE_BUILD_TYPE template_debug)
endif()

# Auto-detect platform
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	set(DEFAULT_PLATFORM "LINUX")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	set(DEFAULT_PLATFORM "WINDOWS")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
	set(DEFAULT_PLATFORM "MACOS")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Emscripten") # Set by providing Emscripten toolchain
	set(DEFAULT_PLATFORM "WEB")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Android") # Set by providing Android toolchain
	set(DEFAULT_PLATFORM "ANDROID")
else()
	message(FATAL_ERROR "Could not auto-detect platform for \"${CMAKE_SYSTEM_NAME}\" automatically, please specify with -DPLATFORM=<platform>")
endif()
set(PLATFORM "${DEFAULT_PLATFORM}" CACHE STRING "[Auto-detected] Target platform (LINUX, MACOS, WINDOWS, ANDROID, IOS, WEB)")

set(GDEXTENSION_DIR "${CMAKE_CURRENT_SOURCE_DIR}/gdextension" CACHE FILEPATH "Path to a directory containing GDExtension interface header")

set(GDEXTENSION_API_FILE "${CMAKE_CURRENT_SOURCE_DIR}/gdextension/extension_api.json" CACHE FILEPATH "Path to GDExtension API JSON file")

set(FLOAT_PRECISION "SINGLE" CACHE STRING "Floating-point precision level (SINGLE, DOUBLE)")

set(OPTIMIZE "AUTO" CACHE STRING "The desired optimization flags (NONE, CUSTOM, DEBUG, SPEED, SPEED_TRACE, SIZE)")

set(SYMBOLS_VISIBILITY "AUTO" CACHE STRING "Symbols visibility on GNU platforms (AUTO, VISIBLE, HIDDEN)")

#TODO: custom .gdextension template file to add shared library as dependency
set(GODOT_CPP_LIBRARY_TYPE "STATIC" CACHE STRING "[Experimental] Library type (STATIC, SHARED)")


option(DEV_BUILD "Developer build with dev-only debugging code" OFF)

option(DEBUG_SYMBOLS "Build with debugging symbols" ON)

option(USE_HOT_RELOAD "Enable the extra accounting required to support hot reload" ON)

# Disable exception handling. Godot doesn't use exceptions anywhere, and this
# saves around 20% of binary size and very significant build time (GH-80513).
option(GODOT_DISABLE_EXCEPTIONS "Force disabling exception handling code" ON)

# Optionally mark headers as SYSTEM
option(GODOT_CPP_SYSTEM_HEADERS "Mark the header files as SYSTEM. This may be useful to supress warnings in projects including this one" OFF)
set(GODOT_CPP_SYSTEM_HEADERS_ATTRIBUTE "")
if(GODOT_CPP_SYSTEM_HEADERS)
	set(GODOT_CPP_SYSTEM_HEADERS_ATTRIBUTE SYSTEM)
endif()

# Enable by default when building godot-cpp only
set(DEFAULT_WARNING_AS_ERROR OFF)
if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
	set(DEFAULT_WARNING_AS_ERROR ON)
endif()
set(GODOT_CPP_WARNING_AS_ERROR ${DEFAULT_WARNING_AS_ERROR} CACHE BOOL "Treat warnings as errors")

option(GENERATE_TEMPLATE_GET_NODE "Generate a template version of the Node class's get_node" ON)

###

# Compiler warnings and compiler check generators
include(GodotCompilerWarnings)

# Create the correct name (godot-cpp.platform.target.arch)
if(${DEV_BUILD})
	string(APPEND LIBRARY_SUFFIX ".dev")
endif()

if(${FLOAT_PRECISION} STREQUAL "DOUBLE")
	string(APPEND LIBRARY_SUFFIX ".double")
endif()

# Workaround of $<CONFIG> expanding to "" when default build set
set(CONFIG "$<IF:$<STREQUAL:,$<CONFIG>>,${CMAKE_BUILD_TYPE},$<CONFIG>>")

string(TOLOWER ".${PLATFORM}" platform)
string(PREPEND LIBRARY_SUFFIX "${platform}.${CONFIG}")

# Default optimization levels if OPTIMIZE=AUTO, for multi-config support
set(DEFAULT_OPTIMIZATION_DEV "$<AND:$<STREQUAL:${OPTIMIZE},AUTO>,$<BOOL:${DEV_BUILD}>>")
set(DEFAULT_OPTIMIZATION_DEBUG_FEATURES "$<AND:$<NOT:${DEFAULT_OPTIMIZATION_DEV}>,$<STREQUAL:${OPTIMIZE},AUTO>,$<OR:$<STREQUAL:${CONFIG},editor>,$<STREQUAL:${CONFIG},template_debug>>>")
set(DEFAULT_OPTIMIZATION "$<$<AND:$<NOT:$<OR:${DEFAULT_OPTIMIZATION_DEV},${DEFAULT_OPTIMIZATION_DEBUG_FEATURES}>>,STREQUAL:${OPTIMIZE},AUTO>>")

list(APPEND GODOT_DEFINITIONS
	GDEXTENSION

	$<${compiler_is_msvc}:
		$<$<BOOL:${GODOT_DISABLE_EXCEPTIONS}>:
			_HAS_EXCEPTIONS=0
		>
	>

	$<$<STREQUAL:${FLOAT_PRECISION},DOUBLE>:
		REAL_T_IS_DOUBLE
	>
	$<$<AND:$<NOT:$<STREQUAL:${CONFIG},template_release>>,$<BOOL:${USE_HOT_RELOAD}>>:
		HOT_RELOAD_ENABLE
	>
	$<$<STREQUAL:${CONFIG},editor>:
		TOOLS_ENABLED
	>

	$<$<BOOL:${DEV_BUILD}>:
		DEV_ENABLED
	>
	$<$<NOT:$<BOOL:${DEV_BUILD}>>:
		NDEBUG
	>

	$<$<NOT:$<STREQUAL:${CONFIG},template_release>>:
		DEBUG_ENABLED
		DEBUG_METHODS_ENABLED
	>
)

list(APPEND GODOT_CC_FLAGS
	$<${compiler_is_msvc}:
		$<$<BOOL:${DEBUG_SYMBOLS}>:
			/Zi
			/FS
		>

		$<$<OR:$<STREQUAL:${OPTIMIZE},SPEED>,${DEFAULT_OPTIMIZATION}>:
			/O2
		>
		$<$<OR:$<STREQUAL:${OPTIMIZE},SPEED_TRACE>,${DEFAULT_OPTIMIZATION_DEBUG_FEATURES}>:
			/O2
		>
		$<$<STREQUAL:${OPTIMIZE},SIZE>:
			/O1
		>
		$<$<OR:$<STREQUAL:${OPTIMIZE},DEBUG>,$<STREQUAL:${OPTIMIZE},NONE>,${DEFAULT_OPTIMIZATION_DEV}>:
			/Od
		>
	>
	$<$<NOT:${compiler_is_msvc}>:
		$<$<BOOL:${DEBUG_SYMBOLS}>:
			-gdwarf-4
		
			$<$<BOOL:${DEV_BUILD}>:
				-g3
			>
			$<$<NOT:$<BOOL:${DEV_BUILD}>>:
				-g2
			>
		>

		$<$<STREQUAL:${SYMBOLS_VISIBILITY},VISIBLE>:
			-fvisibility=default
		>
		$<$<STREQUAL:${SYMBOLS_VISIBILITY},HIDDEN>:
			-fvisibility=hidden
		>

		$<$<OR:$<STREQUAL:${OPTIMIZE},SPEED>>:
			-O3
		>
		$<$<OR:$<STREQUAL:${OPTIMIZE},SPEED_TRACE>,${DEFAULT_OPTIMIZATION_DEBUG_FEATURES}>:
			-O2
		>
		$<$<STREQUAL:${OPTIMIZE},SIZE>:
			-Os
		>
		$<$<STREQUAL:${OPTIMIZE},DEBUG>:
			-Og
		>
		$<$<OR:$<STREQUAL:${OPTIMIZE},NONE>,${DEFAULT_OPTIMIZATION_DEV}>:
			-O0
		>
	>
)

list(APPEND GODOT_CXX_FLAGS
	$<${compiler_is_msvc}:
		$<$<NOT:$<BOOL:${GODOT_DISABLE_EXCEPTIONS}>>:
			/EHsc
		>
	>
	$<$<NOT:${compiler_is_msvc}>:
		$<$<BOOL:${GODOT_DISABLE_EXCEPTIONS}>:
			-fno-exceptions	
		>
	>
)

list(APPEND GODOT_LINK_FLAGS
	$<${compiler_is_msvc}:
		$<$<BOOL:${DEBUG_SYMBOLS}>:
			/DEBUG:FULL
		>

		$<$<STREQUAL:${OPTIMIZE},SPEED>:
			/OPT:REF
		>
		$<$<OR:$<STREQUAL:${OPTIMIZE},SPEED_TRACE>,${DEFAULT_OPTIMIZATION_DEBUG_FEATURES}>:
			/OPT:REF
			/OPT:NOICF
		>
		$<$<STREQUAL:${OPTIMIZE},SIZE>:
			/OPT:REF
		>
	>
	$<$<NOT:${compiler_is_msvc}>:
		$<$<STREQUAL:${SYMBOLS_VISIBILITY},VISIBLE>:
			-fvisibility=default
		>
		$<$<STREQUAL:${SYMBOLS_VISIBILITY},HIDDEN>:
			-fvisibility=hidden
		>

		$<$<NOT:$<BOOL:${DEBUG_SYMBOLS}>>:
			$<$<CXX_COMPILER_ID:AppleClang>: # SCons: not is_vanilla_clang(env)
				"-Wl,-S"
				"-Wl,-x"
				"-Wl,-dead_strip"
			>
			$<$<NOT:$<CXX_COMPILER_ID:AppleClang>>:
				"-s"
			>
		>
	>
)

# Platform-specific options
if("${PLATFORM}" STREQUAL "LINUX")
	include(linux)
elseif("${PLATFORM}" STREQUAL "MACOS")
	include(macos)
elseif("${PLATFORM}" STREQUAL "WINDOWS")
	include(windows)
elseif("${PLATFORM}" STREQUAL "ANDROID")
	include(android)
elseif("${PLATFORM}" STREQUAL "IOS")
	include(ios)
elseif("${PLATFORM}" STREQUAL "WEB")
	include(web)
else()
	message(FATAL_ERROR "Platform not supported: ${PLATFORM}")
endif()

# Write all flags to file for cmake configuration debug
file(GENERATE OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/flags.txt"
	CONTENT
	"C_FLAGS '${GODOT_CC_FLAGS}'\nCXX_FLAGS '${GODOT_CXX_FLAGS}'\nLINK_FLAGS '${GODOT_LINK_FLAGS}'\nCOMPILE_WARNING_FLAGS '${GODOT_COMPILE_WARNING_FLAGS}'\n"
	TARGET ${PROJECT_NAME}
)
