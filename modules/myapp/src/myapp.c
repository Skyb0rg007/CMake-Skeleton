#include "utils.h"
#include "mylib.h"

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++) {
        printfln("Arg%d: %s", i, argv[i]);
    }

    mylib_helloworld();
    return 0;
}
