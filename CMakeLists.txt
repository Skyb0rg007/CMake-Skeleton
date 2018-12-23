#########################################################################################
#
#
#	 CMake build script
#	== == == == == == == 
#
#
#########################################################################################
cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

project(Myproj
    VERSION 0.1.1 
    LANGUAGES C 
    DESCRIPTION "CMake skeleyon project for C."
    HOMEPAGE_URL "https://github.com/Skyb0rg007/CMake-Skeleton"
)

##########################################################################################
# CMake status output log
#
##########################################################################################
message(STATUS "CMake version   : " "${CMAKE_SYSTEM_VERSION}")
message(STATUS "Compiler        : " "${CMAKE_C_COMPILER}"    )
message(STATUS "Operating System: " "${CMAKE_SYSTEM}"        )
message(STATUS "I am building   : " "${PROJECT_NAME}"        )

##########################################################################################
# CMake project
#
##########################################################################################

# Enable tests as long as BUILD_TESTING is ON
include(CTest)

# Enable LTO on Release builds
include(CheckIPOSupported)
check_ipo_supported(RESULT ipo_supported)
if(ipo_supported)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)
endif()

# Enable running and testing on Windows under Debug
# To test other configs, just `install' to a local dir before testing
if(WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})
endif()


add_subdirectory(thirdparty)
add_subdirectory(modules)

##########################################################################################
# CPack set package support
#
##########################################################################################
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}"       )
set(CPACK_PACKAGE_VENDOR "Skyb0rg Developer labs")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A simple CMake project in C."   )
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.md")
set(CPACK_RESOURCE_FILE_README  "${CMAKE_CURRENT_SOURCE_DIR}/README.md" )

##########################################################################################
# CPack include
#
##########################################################################################
include(CPack)
