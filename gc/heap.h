#include "common.h"

void GC_set_heap_boundaries(void)
{
    GC_heap_begin = 0;
    GC_heap_end = 0;

    for (size_t i = 0; i < GC_object_count; i++)
    {
        GC_ALLOC_INFO *info = &GC_allocations[i];
        GC_heap_begin = MIN(GC_heap_begin, info->address);
        GC_heap_end = MAX(GC_heap_end, GC_heap_begin + info->size);
    }
}