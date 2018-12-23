
add_executable(Myproj.utils.test1
    test1.c
)
target_link_libraries(Myproj.utils.test1
    PUBLIC
        Myproj::utils
)

add_test(Myproj.utils.test1 Myproj.utils.test1)
