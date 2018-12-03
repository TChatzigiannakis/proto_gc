#include "common.h"

GC_ALLOC_INFO *GC_resolve_internal(uintptr_t ptr)
{
    if (IN_RANGE(ptr, GC_heap_begin, GC_heap_end))
    {
        for (size_t i = 0; i < GC_object_count; i++)
        {
            GC_ALLOC_INFO *info = &GC_allocations[i];
            if (IN_RANGE(ptr, info->address, info->address + info->size))
            {
                return info;
            }
        }
    }

    return NULL;
}