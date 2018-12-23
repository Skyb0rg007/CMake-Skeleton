
add_executable(Myproj.mylib.test1
    test1.c
)
target_link_libraries(Myproj.mylib.test1
    PUBLIC
        Myproj::mylib
)

add_test(Myproj.mylib.test1 Myproj.mylib.test1)
