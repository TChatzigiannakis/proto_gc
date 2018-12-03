#include <setjmp.h>

#include "common.h"

void GC_collect(void)
{
    jmp_buf buf;
    setjmp(buf);

    GC_set_stack_boundaries();
    GC_set_heap_boundaries();

    GC_scan(MIN(GC_stack_begin, GC_stack_end), MAX(GC_stack_begin, GC_stack_end));

    GC_cleanup();

    GC_compact();

    for (size_t i = 0; i < GC_capacity; i++)
    {
        GC_allocations[i].alive = 0;
    }
}