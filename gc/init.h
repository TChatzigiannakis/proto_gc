#include "common.h"

void GC_init(void)
{
    int a = 0;
    int *p = &a;
    GC_stack_begin = (uintptr_t)p;

    GC_allocations = (GC_ALLOC_INFO *)calloc(16, sizeof(GC_ALLOC_INFO));
    GC_capacity = 16;
}