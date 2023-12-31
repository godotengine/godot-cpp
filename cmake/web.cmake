# Used with Emscripted toolchain at *toolchain_dir*/cmake/Modules/Platform/Emscripten.cmake

set(ARCH "wasm32" CACHE STRING "Target architecture (wasm32, CUSTOM)")

string(REGEX MATCH "32$|64$" DEFAULT_BITS "${ARCH}")
set(BITS "${DEFAULT_BITS}" CACHE STRING "Architecture bits. Needs to be set manually for custom architecture")


list(APPEND GODOT_DEFINITIONS
	WEB_ENABLED
	UNIX_ENABLED
)

list(APPEND GODOT_CC_FLAGS
	-sUSE_PTHREADS=1
)

list(APPEND GODOT_CXX_FLAGS
	-sSIDE_MODULE=1
)

list(APPEND GODOT_LINK_FLAGS
	-sUSE_PTHREADS=1
	-sSIDE_MODULE=1
)
