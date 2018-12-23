
# Obviously you have to do stuff differently to test the executable

add_executable(Myproj.myapp.test1
    test1.c
)
target_link_libraries(Myproj.myapp.test1
    PUBLIC
        Myproj::mylib
)

# Use this long name since executables and tests are registered globally
# Also running ctest -R 'Myproj.myapp.' will limit to this file
add_test(Myproj.myapp.test1 Myproj.myapp.test1)
