#include "common.h"

void GC_set_heap_boundaries(void)
{
    GC_heap_begin = 0;
    GC_heap_end = 0;

    if (GC_object_count)
    {
        GC_heap_begin = GC_allocations[0].address;
        GC_heap_end = GC_heap_begin + GC_allocations[0].size;
    }

    for (size_t i = 1; i < GC_object_count; i++)
    {
        GC_ALLOC_INFO *info = &GC_allocations[i];
        GC_heap_begin = MIN(GC_heap_begin, info->address);
        GC_heap_end = MAX(GC_heap_end, info->address + info->size);
    }
}