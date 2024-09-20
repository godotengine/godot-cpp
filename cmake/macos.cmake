set(GODOT_ARCH "universal" CACHE STRING "Target architecture (universal, arm64, x86_64, custom)")

set(GODOT_MACOS_DEPLOYMENT_TARGET "default" CACHE STRING "")

if (${GODOT_ARCH} STREQUAL "universal")
	set(DEFAULT_GODOT_BITS 64)
else()
	string(REGEX MATCH "32$|64$" DEFAULT_GODOT_BITS "${GODOT_ARCH}")
endif()
set(GODOT_BITS "${DEFAULT_GODOT_BITS}" CACHE STRING "Architecture bits. Needs to be set manually for custom architecture")


list(APPEND GODOT_DEFINITIONS
	MACOS_ENABLED
	UNIX_ENABLED
)

list(APPEND GODOT_C_FLAGS
	$<$<STREQUAL:${GODOT_ARCH},universal>:
		"SHELL:-arch x86_64"
		"SHELL:-arch arm64"
	>
	$<$<NOT:$<STREQUAL:${GODOT_ARCH},universal>>:
		"SHELL:-arch ${GODOT_ARCH}"
	>

	$<$<NOT:$<STREQUAL:${GODOT_MACOS_DEPLOYMENT_TARGET},default>>:
	-mmacosx-version-min=${GODOT_MACOS_DEPLOYMENT_TARGET}
	>
)

list(APPEND GODOT_LINK_FLAGS
	-framework
        Cocoa
        -Wl,-undefined,dynamic_lookup

	$<$<STREQUAL:${GODOT_ARCH},universal>:
		"SHELL:-arch x86_64"
		"SHELL:-arch arm64"
	>
	$<$<NOT:$<STREQUAL:${GODOT_ARCH},universal>>:
		"SHELL:-arch ${GODOT_ARCH}"
	>

	$<$<NOT:$<STREQUAL:${GODOT_MACOS_DEPLOYMENT_TARGET},default>>:
		-mmacosx-version-min=${GODOT_MACOS_DEPLOYMENT_TARGET}
	>
)
