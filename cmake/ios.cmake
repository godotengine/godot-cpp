message(WARNING "IOS configuration is not tested and may not work.")

set(ARCH "universal" CACHE STRING "Target architecture (universal, arm64, x86_64, CUSTOM)")

set(IOS_MIN_VERSION "12.0" CACHE STRING "Target minimum iphoneos/iphonesimulator version")

option(IOS_SIMULATOR "Target iOS Simulator" OFF)

if (${ARCH} STREQUAL "universal")
	set(DEFAULT_BITS 64)
else()
	string(REGEX MATCH "32$|64$" DEFAULT_BITS "${ARCH}")
endif()
set(BITS "${DEFAULT_BITS}" CACHE STRING "Architecture bits. Needs to be set manually for custom architecture")


list(APPEND GODOT_DEFINITIONS
	IOS_ENABLED
	UNIX_ENABLED
)

list(APPEND GODOT_CC_FLAGS
	$<$<STREQUAL:${CMAKE_SYSTEM_NAME},Darwin>:
		-stdlib=libc++
	>

	$<$<BOOL:${IOS_SIMULATOR}>:
		-mios-simulator-version-min=${IOS_MIN_VERSION}
	>
	$<$<NOT:$<BOOL:${IOS_SIMULATOR}>>:
		-miphoneos-version-min=${IOS_MIN_VERSION}
	>

	$<$<STREQUAL:${ARCH},universal>:
		$<$<BOOL:${IOS_SIMULATOR}>:
			"SHELL:-arch x86_64"
			"SHELL:-arch arm64"
		>
		$<$<NOT:$<BOOL:${IOS_SIMULATOR}>>:
			"SHELL:-arch arm64"
		>
	>
	$<$<NOT:$<STREQUAL:${ARCH},universal>>:
		"-arch ${ARCH}"
	>
)

list(APPEND GODOT_LINK_FLAGS
	$<$<STREQUAL:${ARCH},universal>:
		$<$<BOOL:${IOS_SIMULATOR}>:
			"SHELL:-arch x86_64"
			"SHELL:-arch arm64"
		>
		$<$<NOT:$<BOOL:${IOS_SIMULATOR}>>:
			"SHELL:-arch arm64"
		>
	>
	$<$<NOT:$<STREQUAL:${ARCH},universal>>:
		"SHELL:-arch ${ARCH}"
	>
)

