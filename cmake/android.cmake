# Used with android toolchain at $ANDROID_NDK/build/cmake/android.toolchain.cmake

set(GODOT_ARCH "arm64" CACHE STRING "Target architecture (arm64, x86_64, arm32, x86_32, custom")

if(${ANDROID_PLATFORM} VERSION_LESS 21)
	message(FATAL_ERROR "Minimum supported API level is 21 (-DANDROID_PLATFORM=21)")
endif()

# This must be kept in sync with the value in https://github.com/godotengine/godot/blob/master/platform/android/detect.py#L58.
set(ANDROID_NDK_VERSION_EXPECTED "23.2.8568313")
if(NOT "${ANDROID_NDK_REVISION}" STREQUAL "${ANDROID_NDK_VERSION_EXPECTED}")
	message(FATAL_ERROR "Android NDK version '${ANDROID_NDK_VERSION_EXPECTED}' expected, got '${ANDROID_NDK_REVISION}'")
endif()

string(REGEX MATCH "32$|64$" DEFAULT_GODOT_BITS "${GODOT_ARCH}")
set(GODOT_BITS "${DEFAULT_GODOT_BITS}" CACHE STRING "Architecture bits. Needs to be set manually for custom architecture")


list(APPEND GODOT_DEFINITIONS
	ANDROID_ENABLED
	UNIX_ENABLED
)

list(APPEND GODOT_C_FLAGS
	$<$<STREQUAL:${GODOT_ARCH},arm32>:
		--target=armv7a-linux-androideabi${ANDROID_PLATFORM}
		-march=armv7-a

		-mfpu=neon
	>
	$<$<STREQUAL:${GODOT_ARCH},arm64>:
		--target=aarch64-linux-android${ANDROID_PLATFORM}
		-march=armv8-a
	>
	$<$<STREQUAL:${GODOT_ARCH},x86_32>:
		--target=i686-linux-android${ANDROID_PLATFORM}
		-march=i686

		-mstackrealign
	>
	$<$<STREQUAL:${GODOT_ARCH},x86_64>:
		--target=x86_64-linux-android${ANDROID_PLATFORM}
		-march=x86-64
	>
)

list(APPEND GODOT_LINK_FLAGS
	$<$<STREQUAL:${GODOT_ARCH},arm32>:
		--target=armv7a-linux-androideabi${ANDROID_PLATFORM}
		-march=armv7-a
	>
	$<$<STREQUAL:${GODOT_ARCH},arm64>:
		--target=aarch64-linux-android${ANDROID_PLATFORM}
		-march=armv8-a
	>
	$<$<STREQUAL:${GODOT_ARCH},x86_32>:
		--target=i686-linux-android${ANDROID_PLATFORM}
		-march=i686
	>
	$<$<STREQUAL:${GODOT_ARCH},x86_64>:
		--target=x86_64-linux-android${ANDROID_PLATFORM}
		-march=x86-64
	>
)
