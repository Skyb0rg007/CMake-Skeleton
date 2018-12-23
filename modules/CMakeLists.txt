include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

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
