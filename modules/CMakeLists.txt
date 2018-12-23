include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Setup RPATHs
# This assumes exe vs lib is <prefix>/<bindir>/exe vs <prefix>/<libdir>/lib
if(APPLE)
    set(CMAKE_INSTALL_RPATH "@loader_path/../${CMAKE_INSTALL_LIBDIR}")
else()
    set(CMAKE_INSTALL_RPATH "\$ORIGIN/../${CMAKE_INSTALL_LIBDIR}")
endif()

# Enable running and testing on Windows under Debug
# To test other configs, just `install' to a local dir before testing
if(WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})
endif()

# Add the following directories to the project
add_subdirectory(utils)
add_subdirectory(mylib)
add_subdirectory(myapp)

# Configure a custom import file and install it
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/MyprojConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/installation/MyprojConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Myproj/
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/installation/MyprojConfig.cmake
    COMPONENT Development
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Myproj
)
# Write and install a version file
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/installation/MyprojConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY ExactVersion
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/installation/MyprojConfigVersion.cmake
    COMPONENT Development
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Myproj/
)
