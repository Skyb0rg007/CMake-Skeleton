#include "mylib.h"
#include "mylib_internal.h"
#include "mylib_config.h"
#include "utils.h"
#include <stdio.h>

void mylib_helloworld(void)
{
    printf("Hello from mylib version %s!\n", MYLIB_VERSION);
    printfln("%s", MYLIB_SECRET);
}
