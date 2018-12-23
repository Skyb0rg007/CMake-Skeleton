
add_executable(myapp
    src/myapp.c
)
target_link_libraries(myapp
    Myproj::mylib
    Myproj::utils
)
add_executable(Myproj::myapp ALIAS myapp)

install(TARGETS myapp EXPORT myproj-targets
    RUNTIME 
        DESTINATION ${CMAKE_INSTALL_BINDIR}
        COMPONENT Runtime
)


if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
