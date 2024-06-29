
include("CMakePackageConfigHelpers")
include("GNUInstallDirs")

# Install the library and headers to their respective install location
# CMAKE_INSTALL_ are used to allow the package manager to chose the install location
# Components are used so that if godot-cpp is a subproject, the user can chose not to install it
install(TARGETS "godot-cpp"
	EXPORT "godot-cpp-target"
	ARCHIVE
		DESTINATION "${CMAKE_INSTALL_LIBDIR}"
		COMPONENT "godot-cpp-dev"
)
install(
	DIRECTORY
		"${CMAKE_CURRENT_SOURCE_DIR}/include/"
		"${CMAKE_CURRENT_BINARY_DIR}/gen/include/"
	DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
	COMPONENT "godot-cpp-dev"
)
# Install the gdextension files
# The gdextension header is assumed to be the root include directory
# As the JSON file is neither a header nor lib file it goes to the datadir
install(FILES "${GODOT_GDEXTENSION_DIR}/gdextension_interface.h"
	DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
	COMPONENT "godot-cpp-dev"
)
install(FILES "${GODOT_GDEXTENSION_API_FILE}"
	DESTINATION "${CMAKE_INSTALL_DATADIR}/godot-cpp"
	COMPONENT "godot-cpp-dev"
)

# Install the export config file
# This allows this library to be easily consumed by cmake projects:
#	find_package("godot-cpp" 4.2.0 CONFIG REQUIRED)
#	target_link_libaries("my-project" PRIVATE "godot::cpp")
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.cmake"
	RENAME "godot-cpp-config.cmake"
	DESTINATION "${CMAKE_INSTALL_DATADIR}/godot-cpp"
	COMPONENT "godot-cpp-dev"
)
install(EXPORT "godot-cpp-target"
	NAMESPACE "godot::"
	DESTINATION "${CMAKE_INSTALL_DATADIR}/godot-cpp"
	COMPONENT "godot-cpp-dev"
)

if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.19") # string(JSON...) only available in cmake v3.19+
	# Use the JSON api file to get the version
	file(READ "${GODOT_GDEXTENSION_API_FILE}" GODOT_GDEXTENSION_API_JSON)
	# GODOT_API_VERSION_MAJOR = GODOT_GDEXTENSION_API_JSON["header"]["version_major"]
	string(JSON GODOT_API_VERSION_MAJOR GET "${GODOT_GDEXTENSION_API_JSON}" "header" "version_major")
	string(JSON GODOT_API_VERSION_MINOR GET "${GODOT_GDEXTENSION_API_JSON}" "header" "version_minor")
	string(JSON GODOT_API_VERSION_PATCH GET "${GODOT_GDEXTENSION_API_JSON}" "header" "version_patch")
	set(GODOT_API_VERSION "${GODOT_API_VERSION_MAJOR}.${GODOT_API_VERSION_MINOR}.${GODOT_API_VERSION_PATCH}")
	unset(GODOT_GDEXTENSION_API_JSON)

	# Install the config version file so that the gdextension version can be specified in find_package
	write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/godot-cpp-config-version.cmake"
		VERSION "${GODOT_API_VERSION}"
		COMPATIBILITY SameMinorVersion
	)
	install(FILES "${CMAKE_CURRENT_BINARY_DIR}/godot-cpp-config-version.cmake"
		DESTINATION "${CMAKE_INSTALL_DATADIR}/godot-cpp"
		COMPONENT "godot-cpp-dev"
	)
endif()
