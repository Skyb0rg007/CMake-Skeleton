
# Configure file to give access to macros such as version number
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mylib_config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/include/mylib_config.h
    @ONLY
)
# STATIC vs SHARED not specified - use BUILD_SHARED_LIBS to choose
# Add sources here
add_library(mylib
    src/mylib.c
)
# Use BUILD_INTERFACE to ensure installing doesn't mess things up
target_include_directories(mylib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/public/>
        # For mylib_config.h
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/>
    PRIVATE
        # Local - don't worry about BUILD_INTERFACE
        include/
)
target_link_libraries(mylib
    PRIVATE
        Myproj::utils
)
# Allow namespacing within the build tree
add_library(Myproj::mylib ALIAS mylib)

# Install the targets, exporting the interface
install(TARGETS mylib EXPORT myproj-targets
    RUNTIME # .dll
        DESTINATION ${CMAKE_INSTALL_BINDIR}
        COMPONENT Runtime
    LIBRARY # .so .dynlib
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
        COMPONENT Runtime
    ARCHIVE # .a .lib
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
        COMPONENT Runtime
    # Set the INTERFACE_INCLUDE_DIR for mylib
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
# Install the public headers when installing the Development component
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/public/
    COMPONENT Development
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.h"
)
# ... including the configured file
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/include/mylib_config.h
    COMPONENT Development
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
