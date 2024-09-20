set(GODOT_ARCH "x86_64" CACHE STRING "Target architecture (x86_32, x86_64, arm64, rv64, custom)")

string(REGEX MATCH "32$|64$" DEFAULT_GODOT_BITS "${GODOT_ARCH}")
set(GODOT_BITS "${DEFAULT_GODOT_BITS}" CACHE STRING "Architecture bits. Needs to be set manually for custom architecture")


list(APPEND GODOT_DEFINITIONS
	LINUX_ENABLED
	UNIX_ENABLED
)

list(APPEND GODOT_C_FLAGS
	# -fPIC is controlled by POSITION_INDEPENDENT_CODE property

	$<$<STREQUAL:${GODOT_ARCH},x86_64>:
		-m64
		-march=x86-64
	>
	$<$<STREQUAL:${GODOT_ARCH},x86_32>:
		-m32
		-march=i686
	>
	$<$<STREQUAL:${GODOT_ARCH},arm64>:
		-march=armv8-a
	>
	$<$<STREQUAL:${GODOT_ARCH},rv64>:
		-march=rv64gc
	>
)

list(APPEND GODOT_CXX_FLAGS
	$<$<AND:$<BOOL:${GODOT_USE_HOT_RELOAD}>,${compiler_is_gnu}>:
		-fno-gnu-unique
	>
)

list(APPEND GODOT_LINK_FLAGS
	-Wl,-R,'$$ORIGIN'

	$<$<STREQUAL:${GODOT_ARCH},x86_64>:
		-m64
		-march=x86-64
	>
	$<$<STREQUAL:${GODOT_ARCH},x86_32>:
		-m32
		-march=i686
	>
	$<$<STREQUAL:${GODOT_ARCH},arm64>:
		-march=armv8-a
	>
	$<$<STREQUAL:${GODOT_ARCH},rv64>:
		-march=rv64gc
	>
)

list(APPEND GODOT_COMPILE_WARNING_FLAGS
	-Wwrite-strings
)
