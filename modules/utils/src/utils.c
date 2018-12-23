#include "utils.h"
#include <stdio.h>
#include <stdarg.h>

void printfln(const char *fmt, ...)
{
    va_list va;
    va_start(va, fmt);

    vprintf(fmt, va);
    puts("");

    va_end(va);
}
