message(WARNING "IOS configuration is not tested and may not work.")

set(GODOT_ARCH "universal" CACHE STRING "Target architecture (universal, arm64, x86_64, custom)")

set(GODOT_IOS_MIN_VERSION "12.0" CACHE STRING "Target minimum iphoneos/iphonesimulator version")

option(GODOT_IOS_SIMULATOR "Target iOS Simulator" OFF)

if (${GODOT_ARCH} STREQUAL "universal")
	set(DEFAULT_GODOT_BITS 64)
else()
	string(REGEX MATCH "32$|64$" DEFAULT_GODOT_BITS "${GODOT_ARCH}")
endif()
set(GODOT_BITS "${DEFAULT_GODOT_BITS}" CACHE STRING "Architecture bits. Needs to be set manually for custom architecture")


list(APPEND GODOT_DEFINITIONS
	IOS_ENABLED
	UNIX_ENABLED
)

list(APPEND GODOT_C_FLAGS
	$<$<STREQUAL:${CMAKE_SYSTEM_NAME},Darwin>:
		-stdlib=libc++
	>

	$<$<BOOL:${GODOT_IOS_SIMULATOR}>:
		-mios-simulator-version-min=${GODOT_IOS_MIN_VERSION}
	>
	$<$<NOT:$<BOOL:${GODOT_IOS_SIMULATOR}>>:
		-miphoneos-version-min=${IOS_MIN_VERSION}
	>

	$<$<STREQUAL:${GODOT_ARCH},universal>:
		$<$<BOOL:${GODOT_IOS_SIMULATOR}>:
			"SHELL:-arch x86_64"
			"SHELL:-arch arm64"
		>
		$<$<NOT:$<BOOL:${GODOT_IOS_SIMULATOR}>>:
			"SHELL:-arch arm64"
		>
	>
	$<$<NOT:$<STREQUAL:${GODOT_ARCH},universal>>:
		"-arch ${GODOT_ARCH}"
	>
)

list(APPEND GODOT_LINK_FLAGS
	$<$<STREQUAL:${GODOT_ARCH},universal>:
		$<$<BOOL:${GODOT_IOS_SIMULATOR}>:
			"SHELL:-arch x86_64"
			"SHELL:-arch arm64"
		>
		$<$<NOT:$<BOOL:${GODOT_IOS_SIMULATOR}>>:
			"SHELL:-arch arm64"
		>
	>
	$<$<NOT:$<STREQUAL:${GODOT_ARCH},universal>>:
		"SHELL:-arch ${GODOT_ARCH}"
	>
)
