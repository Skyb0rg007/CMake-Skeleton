
add_library(utils STATIC
    src/utils.c
)
# Consider all utils headers as public
target_include_directories(utils
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
)
# Allow namespaced usage within the build tree
add_library(Myproj::utils ALIAS utils)

install(TARGETS utils EXPORT myproj-targets
    ARCHIVE 
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
        COMPONENT Development
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    COMPONENT Development
    FILES_MATCHING PATTERN "*.h"
)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
