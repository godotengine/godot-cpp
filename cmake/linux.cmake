set(ARCH "x86_64" CACHE STRING "Target architecture (x86_32, x86_64, arm64, rv64, CUSTOM)")

string(REGEX MATCH "32$|64$" DEFAULT_BITS "${ARCH}")
set(BITS "${DEFAULT_BITS}" CACHE STRING "Architecture bits. Needs to be set manually for custom architecture")


list(APPEND GODOT_DEFINITIONS
	LINUX_ENABLED
	UNIX_ENABLED
)

list(APPEND GODOT_CC_FLAGS
	# -fPIC is controlled by POSITION_INDEPENDENT_CODE property 

	$<$<STREQUAL:${ARCH},x86_64>:
		-m64
		-march=x86-64
	>
	$<$<STREQUAL:${ARCH},x86_32>:
		-m32
		-march=i686
	>
	$<$<STREQUAL:${ARCH},arm64>:
		-march=armv8-a
	>
	$<$<STREQUAL:${ARCH},rv64>:
		-march=rv64gc
	>
)

list(APPEND GODOT_CXX_FLAGS
	$<$<AND:$<BOOL:${USE_HOT_RELOAD}>,${compiler_is_gnu}>:
		-fno-gnu-unique
	>
)

list(APPEND GODOT_LINK_FLAGS
	-Wl,-R,'$$ORIGIN'

	$<$<STREQUAL:${ARCH},x86_64>:
		-m64
		-march=x86-64
	>
	$<$<STREQUAL:${ARCH},x86_32>:
		-m32
		-march=i686
	>
	$<$<STREQUAL:${ARCH},arm64>:
		-march=armv8-a
	>
	$<$<STREQUAL:${ARCH},rv64>:
		-march=rv64gc
	>
)

list(APPEND GODOT_COMPILE_WARNING_FLAGS
	-Wwrite-strings
)

string(APPEND LIBRARY_SUFFIX ".${ARCH}")

