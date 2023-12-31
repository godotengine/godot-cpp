message(WARNING "MacOS configuration is not tested and may not work.")

set(ARCH "universal" CACHE STRING "Target architecture (universal, arm64, x86_64, CUSTOM)")

set(MACOS_DEPLOYMENT_TARGET "DEFAULT" CACHE STRING "")

if (${ARCH} STREQUAL "universal")
	set(DEFAULT_BITS 64)
else()
	string(REGEX MATCH "32$|64$" DEFAULT_BITS "${ARCH}")
endif()
set(BITS "${DEFAULT_BITS}" CACHE STRING "Architecture bits. Needs to be set manually for custom architecture")


list(APPEND GODOT_DEFINITIONS
	MACOS_ENABLED
	UNIX_ENABLED
)

list(APPEND GODOT_CC_FLAGS
	$<$<STREQUAL:${ARCH},universal>:
		"SHELL:-arch x86_64"
		"SHELL:-arch arm64"
	>
	$<$<NOT:$<STREQUAL:${ARCH},universal>>:
		"SHELL:-arch ${ARCH}"
	>

	$<$<NOT:$<STREQUAL:${MACOS_DEPLOYMENT_TARGET},DEFAULT>>:
		-mmacosx-version-min=${MACOS_DEPLOYMENT_TARGET}
	>
)

list(APPEND GODOT_LINK_FLAGS
	-framework
        Cocoa
        -Wl,-undefined,dynamic_lookup

	$<$<STREQUAL:${ARCH},universal>:
		"SHELL:-arch x86_64"
		"SHELL:-arch arm64"
	>
	$<$<NOT:$<STREQUAL:${ARCH},universal>>:
		"SHELL:-arch ${ARCH}"
	>

	$<$<NOT:$<STREQUAL:${MACOS_DEPLOYMENT_TARGET},DEFAULT>>:
		-mmacosx-version-min=${MACOS_DEPLOYMENT_TARGET}
	>
)

string(APPEND LIBRARY_SUFFIX ".${ARCH}")

