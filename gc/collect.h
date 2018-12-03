#include <setjmp.h>

#include "common.h"

void GC_collect(void)
{
    jmp_buf buf;
    int r = setjmp(buf);

    GC_set_stack_boundaries();
    GC_set_heap_boundaries();
}