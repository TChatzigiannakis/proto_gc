#include "common.h"

void *GC_calloc(size_t count, size_t size)
{
    if (GC_full())
    {
        GC_collect();
        if (GC_full())
        {
            GC_expand();
        }
    }

    void *ptr = calloc(count, size);

    GC_ALLOC_INFO *info = GC_next();
    info->address = (uintptr_t)ptr;
    info->size = count * size;
    info->alive = 0;

    return ptr;
}