#include "common.h"

void GC_resize(size_t count)
{
    GC_allocations = realloc(GC_allocations, count * sizeof(GC_ALLOC_INFO));
    GC_capacity = count;
}