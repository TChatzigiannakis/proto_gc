#include "common.h"

void GC_init(char ***argv)
{
    GC_stack_begin = (uintptr_t)argv;

    GC_allocations = (GC_ALLOC_INFO *)calloc(16, sizeof(GC_ALLOC_INFO));
    GC_capacity = 16;
}