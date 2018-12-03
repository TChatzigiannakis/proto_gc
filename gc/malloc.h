#include "common.h"

void *GC_malloc(size_t size)
{
    if (GC_full())
    {
        GC_collect();
        if (GC_full())
        {
            GC_expand();
        }
    }

    void *ptr = malloc(size);
    if (!ptr)
    {
        GC_collect();
        ptr = malloc(size);
    }

    GC_ALLOC_INFO *info = GC_next();
    info->address = (uintptr_t)ptr;
    info->size = size;
    info->alive = 0;

    return ptr;
}