set(ARCH "x86_64" CACHE STRING "Target architecture (x86_32, x86_64, CUSTOM)")

option(USE_STATIC_CPP "Link MinGW/MSVC C++ runtime libraries statically" ON)

string(REGEX MATCH "32$|64$" DEFAULT_BITS "${ARCH}")
set(BITS "${DEFAULT_BITS}" CACHE STRING "Architecture bits. Needs to be set manually for custom architecture")


list(APPEND GODOT_DEFINITIONS
	WINDOWS_ENABLED

	$<${compiler_is_msvc}:
		TYPED_METHOD_BIND
		NOMINMAX
	>
)

list(APPEND GODOT_CC_FLAGS
	$<${compiler_is_msvc}:
		/utf-8

		$<$<BOOL:${USE_STATIC_CPP}>:
			/MT
		>
		$<$<NOT:$<BOOL:${USE_STATIC_CPP}>>:
			/MD
		>
	>
)

list(APPEND GODOT_LINK_FLAGS
	$<${compiler_is_msvc}:
		/WX
	>
	$<$<NOT:${compiler_is_msvc}>:
		-Wl,--no-undefined

		$<$<BOOL:${USE_STATIC_CPP}>:
			-static
			-static-libgcc
                	-static-libstdc++
		>
	>
)

list(APPEND GODOT_COMPILE_WARNING_FLAGS
	$<$<NOT:${compiler_is_msvc}>:
		-Wwrite-strings
	>
)

